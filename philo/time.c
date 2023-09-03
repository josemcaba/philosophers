/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:30:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/03 02:07:08 by jocaball         ###   ########.fr       */
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
The 50 microseconds allows the "over_mutex" to be freed long enough for
all processes to use it while a philosopher is "eating" or "sleeping".
A maximum of 500 microseconds should be set so that between the two states
they do not add up to one millisecond. (Keep in mind that the "sleeping" 
state itself already has a small delay built into it).
The greater this number, the greater number of philosophers can be managed.
*/
void	ft_wait(long msec, t_philo *philo)
{
	long	start_time;

	start_time = now();
	pthread_mutex_lock(&philo->data->over_mtx);
	while ((now() - start_time < msec) && !philo->data->over)
	{
		pthread_mutex_unlock(&philo->data->over_mtx);
		usleep(50);
		pthread_mutex_lock(&philo->data->over_mtx);
	}
	pthread_mutex_unlock(&philo->data->over_mtx);
}
