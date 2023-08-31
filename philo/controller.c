/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:55:34 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/31 11:55:53 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

void	controller(t_data *data, t_philo **philos)
{
	int	over;
	int i;

 	if (data->nbr_philos == 1)
		return ;
	over = 0;
	while (!over)
	{
		/* Check dead */
		i = -1;
		while (!over && (++i < data->nbr_philos))
		{
			usleep(50);
			pthread_mutex_lock(&(*philos)[i].black_hole_mtx);
			if (now() >= (*philos)[i].black_hole)
			{
				pthread_mutex_lock(&data->over_mtx);
				pthread_mutex_lock(&data->print_mtx);
				data->over = 1;
				over = 1;
				printf("%ld %d %s\n", now(), (*philos)[i].id, "died");
				pthread_mutex_unlock(&data->print_mtx);
				pthread_mutex_unlock(&data->over_mtx);
			}
			pthread_mutex_unlock(&(*philos)[i].black_hole_mtx);
		}
		/* Check meals */
		pthread_mutex_lock(&data->full_philos_mtx);
		if (data->full_philos == data->nbr_philos)
		{
			pthread_mutex_lock(&data->over_mtx);
			pthread_mutex_lock(&data->print_mtx);
			data->over = 1;
			over = 1;
			printf("%ld All philosophers have eaten at least %d times\n", now(), data->min_meals);
			pthread_mutex_unlock(&data->print_mtx);
			pthread_mutex_unlock(&data->over_mtx);
		}
		pthread_mutex_unlock(&data->full_philos_mtx);
	}
	philos_join(data, philos, data->nbr_philos);
	free(*philos);
}
