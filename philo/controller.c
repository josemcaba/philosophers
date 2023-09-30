/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:55:34 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/30 22:47:36 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutexes_destroy(t_data *data, t_philo **philos, int nbr)
{
	int	i;

	i = -1;
	while (++i < nbr)
	{
		pthread_mutex_destroy(&(*philos)[i].black_hole_mtx);
		pthread_mutex_destroy(&(*philos)[i].right_fork);
	}
	pthread_mutex_destroy(&data->nbr_full_philos_mtx);
	pthread_mutex_destroy(&data->over_mtx);
	pthread_mutex_destroy(&data->print_mtx);
	pthread_mutex_destroy(&data->dummy_fork);
	free(*philos);
}

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
	mutexes_destroy(data, philos, data->nbr_philos);
}

static int	check_full(t_data *data)
{
	int	over;

	over = 0;
	pthread_mutex_lock(&data->nbr_full_philos_mtx);
	if (data->nbr_full_philos == data->nbr_philos)
	{
		pthread_mutex_lock(&data->over_mtx);
		if (!data->over)
			printf("%06ld All philosophers have eaten at least %d times\n", \
					now() - data->start_time, data->min_nbr_meals);
		data->over = 1;
		over = 1;
		pthread_mutex_unlock(&data->over_mtx);
	}
	pthread_mutex_unlock(&data->nbr_full_philos_mtx);
	return (over);
}

static int	check_dead(t_data *data, t_philo **philos)
{
	int	i;
	int	over;

	over = 0;
	i = -1;
	while ((++i < data->nbr_philos))
	{
		pthread_mutex_lock(&(*philos)[i].black_hole_mtx);
		if (now() >= (*philos)[i].black_hole)
		{
			pthread_mutex_lock(&data->over_mtx);
			if (!data->over)
				printf("%06ld %d %s\n", now() - data->start_time, \
						(*philos)[i].id, "died");
			data->over = 1;
			over = 1;
			pthread_mutex_unlock(&data->over_mtx);
		}
		pthread_mutex_unlock(&(*philos)[i].black_hole_mtx);
	}
	return (over);
}

void	controller(t_data *data, t_philo **philos)
{
	int	over;

	over = 0;
	while (!over)
	{
		over = check_dead(data, philos);
		if (!over)
			over = check_full(data);
	}
	philos_destroy(data, philos, data->nbr_philos);
}
