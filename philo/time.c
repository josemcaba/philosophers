/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:30:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/03 16:22:27 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	now(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec * 0.001));
}

/*
The 10 microseconds allows the "over_mutex" to be freed long enough for
all threads to use it.
*/
void	ft_wait(long msec, t_data *data)
{
	long	start_time;

	start_time = now();
	pthread_mutex_lock(&data->over_mtx);
	while ((now() - start_time < msec) && !data->over)
	{
		pthread_mutex_unlock(&data->over_mtx);
		usleep(1);
		pthread_mutex_lock(&data->over_mtx);
	}
	pthread_mutex_unlock(&data->over_mtx);
}
