/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:17:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/28 14:20:20 by jocaball         ###   ########.fr       */
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

void	*philosopher(void *arg)
{
	t_philo	*philo;
	long	now;

	philo = (t_philo *)arg;
	now_time(&now);
	philo->data->black_holes[philo->id - 1] = now + philo->data->time_die;
	while (!philo->data->dinner_is_over)
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

int	philos_create(t_data *data, t_philo **philo)
{
	int	i;

	*philo = malloc(data->nbr_philos * sizeof(t_philo));
	if (!(*philo))
	{
		ft_putstr_fd("ERROR: Can not allocate memory for philosophers\n", 2);
		free (data->fork);
		return (EXIT_FAILURE);
	}
	memset(*philo, 0, data->nbr_philos * sizeof(t_philo));
	i = -1;
	while (++i < data->nbr_philos)
	{
		(*philo)[i].data = data;
		(*philo)[i].id = i + 1;
		(*philo)[i].right_fork = &data->fork[i];
		(*philo)[i].left_fork = &data->fork[i];
		if ((i == 0) && (data->nbr_philos > 1))
			(*philo)[i].left_fork = &data->fork[data->nbr_philos - 1];
		else if (data->nbr_philos > 1)
			(*philo)[i].left_fork = &data->fork[i - 1];
		pthread_create(&(*philo)[i].th_id, NULL, philosopher, &(*philo)[i]);
	}
	philos_detach(philo);
	return (EXIT_SUCCESS);
}

