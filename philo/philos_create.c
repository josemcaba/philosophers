/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:04:22 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/05 22:41:13 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_th(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->over_mtx);
	while (!philo->data->over)
	{
		pthread_mutex_unlock(&philo->data->over_mtx);
		thinking(philo);
		eating(philo);
		sleeping(philo);
		pthread_mutex_lock(&philo->data->over_mtx);
	}
	pthread_mutex_unlock(&philo->data->over_mtx);
	return (NULL);
}

int	philos_create(t_data *data, t_philo **philos)
{
	int	i;

	data->start_time = now(data);
	if (data->nbr_philos == 1)
	{
		print_state("is thinking", philos[0]);
		ft_wait(data->time_die, data);
		print_state("died", philos[0]);
	}
	else
	{
		i = -1;
		while (++i < data->nbr_philos)
		{
			(*philos)[i].black_hole = now(data) + data->time_die;
			if (pthread_create(&(*philos)[i].th_id, NULL, \
									philo_th, &(*philos)[i]))
			{
				philos_destroy(data, philos, i);
				//mutexes_destroy(data, philos, data->nbr_philos);
				free(*philos);
				return (error("Can not create thread for a philosopher\n"));
			}
		}
	}
	return (EXIT_SUCCESS);
}
