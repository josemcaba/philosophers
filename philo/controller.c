/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:55:34 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/05 00:42:56 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_full(t_data *data)
{
	pthread_mutex_lock(&data->over_mtx);
	if (data->over)
	{
		pthread_mutex_unlock(&data->over_mtx);
		return ;
	}
	pthread_mutex_unlock(&data->over_mtx);
	pthread_mutex_lock(&data->full_philos_mtx);
	if (data->full_philos == data->nbr_philos)
	{
		pthread_mutex_lock(&data->over_mtx);
		data->over = 1;
		pthread_mutex_unlock(&data->over_mtx);
		pthread_mutex_lock(&data->print_mtx);
		printf("%ld All philosophers have eaten at least %d times\n", \
				now(), data->min_meals);
		pthread_mutex_unlock(&data->print_mtx);
	}
	pthread_mutex_unlock(&data->full_philos_mtx);
}

static void	check_dead(t_data *data, t_philo **philos)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&data->over_mtx);
	while (!data->over && (++i < data->nbr_philos))
	{
		pthread_mutex_unlock(&data->over_mtx);
		pthread_mutex_lock(&(*philos)[i].black_hole_mtx);
		if (now() >= (*philos)[i].black_hole)
		{
			print_state("died", &(*philos)[i]);
			pthread_mutex_lock(&data->over_mtx);
			data->over = 1;
			pthread_mutex_unlock(&data->over_mtx);
		}
		pthread_mutex_unlock(&(*philos)[i].black_hole_mtx);
		pthread_mutex_lock(&data->over_mtx);
	}
	pthread_mutex_unlock(&data->over_mtx);
}

void	controller(t_data *data, t_philo **philos)
{
	if (data->nbr_philos == 1)
		return ;
	pthread_mutex_lock(&data->over_mtx);
	while (!data->over)
	{
		pthread_mutex_unlock(&data->over_mtx);
		check_dead(data, philos);
		check_full(data);
		pthread_mutex_lock(&data->over_mtx);
	}
	pthread_mutex_unlock(&data->over_mtx);
	philos_destroy(data, philos, data->nbr_philos);
	//mutexes_destroy(data, philos, data->nbr_philos);
}
