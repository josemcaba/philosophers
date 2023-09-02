/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:55:34 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/02 11:52:24 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_dead(t_data *data, t_philo **philos)
{
	int	i;

	i = -1;
	while (!data->over && (++i < data->nbr_philos))
	{
		usleep(50);
		pthread_mutex_lock(&(*philos)[i].black_hole_mtx);
		if (now() >= (*philos)[i].black_hole)
		{
			pthread_mutex_lock(&data->print_mtx);
			data->over = 1;
			printf("%ld %d %s\n", now(), (*philos)[i].id, "died");
			pthread_mutex_unlock(&data->print_mtx);
		}
		pthread_mutex_unlock(&(*philos)[i].black_hole_mtx);
	}
}

static void    check_full(t_data *data)
{
	if (data->over)
		return ;
	pthread_mutex_lock(&data->full_philos_mtx);
	if (data->full_philos == data->nbr_philos)
	{
		//pthread_mutex_lock(&data->over_mtx);
		pthread_mutex_lock(&data->print_mtx);
		data->over = 1;
		printf("%ld All philosophers have eaten at least %d times\n", \
				now(), data->min_meals);
		pthread_mutex_unlock(&data->print_mtx);
		//pthread_mutex_unlock(&data->over_mtx);
	}
	pthread_mutex_unlock(&data->full_philos_mtx);
}

void	controller(t_data *data, t_philo **philos)
{
	if (data->nbr_philos == 1)
		return ;
	while (!data->over)
	{
		check_dead(data, philos);
		check_full(data);
	}
	philos_join(data, philos, data->nbr_philos);
	free(*philos);
}
