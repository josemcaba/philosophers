/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:55:34 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/30 15:37:03 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

void	controller(t_data *data, t_philo **philo)
{
	int	finish;
	int i;

	finish = 0;
	while (!finish)
	{
		/* Check dead */
		i = -1;
		while (++i < data->nbr_philos)
		{
			pthread_mutex_lock(&(*philo)[i].black_hole_mtx);
			if (now() > (*philo)[i].black_hole)
			{
				print_state("died", *philo);			
				pthread_mutex_lock(&data->finish_mtx);
				data->finish = 1;
				finish = 1;
				pthread_mutex_unlock(&data->finish_mtx);
			}
			pthread_mutex_unlock(&(*philo)[i].black_hole_mtx);
		}
		/* Check meals */
		pthread_mutex_lock(&data->full_philos_mtx);
		if (data->full_philos == data->nbr_philos)
		{
			pthread_mutex_lock(&data->finish_mtx);
			data->finish = 1;
			finish = 1;
			pthread_mutex_unlock(&data->finish_mtx);
			pthread_mutex_lock(&data->print_mtx);
			printf("%ld All philosophers have eaten at least %d times\n", now(), data->min_meals);
			pthread_mutex_unlock(&data->print_mtx);
		}
		pthread_mutex_unlock(&data->full_philos_mtx);
	}
	i = -1;
	while (++i < data->nbr_philos)
	{
		pthread_join((*philo)[i].th_id, NULL);
	}
	
	//end_dinner(&data, &philo);
		// pthread_join(host_id, NULL);
		// pthread_mutex_destroy(&data.pf);
		// free (data.fork);
		// free (data.black_holes);
}