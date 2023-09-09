/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:55:34 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/09 20:24:29 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philos_destroy(t_data *data, t_philo **philos, int nbr)
{
	int	i;

	pthread_mutex_lock(&data->over_mtx);
	data->over = 1;
	pthread_mutex_unlock(&data->over_mtx);
	pthread_mutex_unlock(&data->dummy_fork);
	i = -1;
	while (++i < nbr)
		pthread_join((*philos)[i].th_id, NULL);
	i = -1;
	while (++i < nbr)
	{
		pthread_mutex_destroy(&(*philos)[i].black_hole_mtx);
		pthread_mutex_destroy(&(*philos)[i].right_fork);
	}
	pthread_mutex_destroy(&data->full_philos_mtx);
	pthread_mutex_destroy(&data->over_mtx);
	pthread_mutex_destroy(&data->print_mtx);
	pthread_mutex_destroy(&data->dummy_fork);
}

static void	check_full(t_data *data)
{
	pthread_mutex_lock(&data->full_philos_mtx);
	if (data->full_philos == data->nbr_philos)
	{
		pthread_mutex_lock(&data->over_mtx);
		if (!data->over)
			printf("%ld All philosophers have eaten at least %d times\n", \
					now() - data->start_time, data->min_meals);
		data->over = 1;
		pthread_mutex_unlock(&data->over_mtx);
	}
	pthread_mutex_unlock(&data->full_philos_mtx);
}

static void	check_dead(t_data *data, t_philo **philos)
{
	int	i;

	i = -1;
	while ((++i < data->nbr_philos))
	{
		pthread_mutex_lock(&(*philos)[i].black_hole_mtx);
		if (now() > (*philos)[i].black_hole)
		{
			pthread_mutex_lock(&data->over_mtx);
			if (!data->over)
				printf("%ld %d %s\n", now() - data->start_time, \
						(*philos)[i].id, "died");
			data->over = 1;
			pthread_mutex_unlock(&data->over_mtx);
		}
		pthread_mutex_unlock(&(*philos)[i].black_hole_mtx);
	}
}

void	controller(t_data *data, t_philo **philos)
{
	pthread_mutex_lock(&data->over_mtx);
	while (!data->over)
	{
		pthread_mutex_unlock(&data->over_mtx);
		check_dead(data, philos);
		check_full(data);
		usleep(50);
		pthread_mutex_lock(&data->over_mtx);
	}
	pthread_mutex_unlock(&data->over_mtx);
	philos_destroy(data, philos, data->nbr_philos);
	free(*philos);
}
