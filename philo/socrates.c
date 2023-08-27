/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socrates.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:17:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/27 02:17:28 by jocaball         ###   ########.fr       */
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
	t_philo	*p;
	long	now;

	p = (t_philo *)arg;

	now_time(&now);
	printf("%ld %d has taken a fork\n", now, p->id);
	now_time(&now);
	printf("%ld %d is eating\n", now, p->id);
	now_time(&now);
	printf("%ld %d is sleeping\n", now, p->id);
	now_time(&now);
	printf("%ld %d is thinking\n", now, p->id);
	now_time(&now);
	printf("%ld %d died\n", now, p->id);

	return (NULL);
}

int	philos_create(t_data *data, t_philo **philo)
{
	int	i;

	*philo = malloc(data->n_philos * sizeof(t_philo));
	if (!(*philo))
	{
		ft_putstr_fd("ERROR: Can not allocate memory for philosophers\n", 2);
		free (data->forks);
		return (EXIT_FAILURE);
	}
	memset(*philo, 0, data->n_philos * sizeof(t_philo));
	i = -1;
	while (++i < data->n_philos)
	{
		(*philo)[i].data = data;
		(*philo)[i].id = i + 1;
		(*philo)[i].right = &data->forks[i];
		(*philo)[i].left = &data->forks[i];
		if ((i == 0) && (data->n_philos > 1))
			(*philo)[i].left = &data->forks[data->n_philos - 1];
		else if (data->n_philos > 1)
			(*philo)[i].left = &data->forks[i - 1];
		pthread_create(&(*philo)[i].th_id, NULL, philosopher, &(*philo)[i]);
	}
	return (EXIT_SUCCESS);
}

void	philos_detach(t_philo **philo)
{
	int	i;

	i = -1;
	while (++i < (*philo)->data->n_philos)
		pthread_detach((*philo)[i].th_id);
}
