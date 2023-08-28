/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:17:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/28 22:36:45 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

/*
Despues de pthread_create hay que asegurarse de liberar los recursos usados
por el propio sistema y para ello, el thread debe haber finalizado.

Si usamos pthread_join para esperar a que termine, la propia pthred_join
libera la memoria.
 
Si finaliza el thread de otra forma que no sea usando pthread_join entonces
debemos liberarlos expresamente con pthread_detach.

Si el programa finaliza antes de que finalice el thread, los recursos no
seran liberados. Produciendo leaks.
*/

void	*philo_th(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->black_hole = now() + philo->data->time_die; 
	while (!philo->data->finish)
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
	return (NULL);
}

void	philos_detach(t_philo **philo)
{
	int	i;

	i = -1;
	while (++i < (*philo)->data->nbr_philos)
		pthread_detach((*philo)[i].th_id);
}

int	philos_init(t_data *data, t_philo **philos)
{
	int	i;

	*philos = malloc(data->nbr_philos * sizeof(t_philo));
	if (!(*philos))
		return (error("Can not allocate memory for philosophers\n"));
	i = -1;
	while (++i < data->nbr_philos)
	{
		(*philos)[i].data = data;
		(*philos)[i].id = i + 1;
		(*philos)[i].nbr_meals = 0;
		if (pthread_mutex_init(&(*philos)[i].meals_hole_mtx, NULL))
		{
			free(*philos);
			return (error("Can not init meals_hole mutex\n"));
		}
		if (pthread_mutex_init(&(*philos)[i].right_fork, NULL))
		{
			free(*philos);
			return (error("Can not init right_fork mutex\n"));
		}
		if (i > 0)
			(*philos)[i].left_fork = &(*philos)[i - 1].right_fork;
	}
	(*philos)[0].left_fork = &(*philos)[data->nbr_philos - 1].right_fork;
	return (EXIT_SUCCESS);
}

int philos_create(t_data *data, t_philo **philos)
{
	int i;
	
	if (philos_init(data, philos))
		return (EXIT_FAILURE);
	i = -1;
	while (++i < data->nbr_philos)
	{
		pthread_mutex_lock(&(*philos)[i].meals_hole_mtx);
		(*philos)[i].black_hole = now() + data->time_die;
		pthread_mutex_unlock(&(*philos)[i].meals_hole_mtx);
		if (pthread_create(&(*philos)[i].th_id, NULL, philo_th, &(*philos)[i]))
			return (error("Can not create thread for philosopher\n"));
	}
	return (EXIT_SUCCESS);
}