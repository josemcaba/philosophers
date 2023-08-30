/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:30:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/30 12:22:36 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

long	now(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (error("Can not get the time\n"));
	return (tv.tv_sec * 1000) + (tv.tv_usec * 0.001);
}

void	wait(long msec, t_philo *philo)
{
	long	start_time;

	start_time = now();
	pthread_mutex_lock(&philo->data->finish_mtx);
	while ((now() - start_time < msec) && !philo->data->finish)
	{
		pthread_mutex_unlock(&philo->data->finish_mtx);
		usleep(100); //¿Se puede rebajar?
		pthread_mutex_lock(&philo->data->finish_mtx);
	}
	pthread_mutex_unlock(&philo->data->finish_mtx);	
}