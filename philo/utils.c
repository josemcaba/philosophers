/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:30:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/10/15 12:08:05 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	now(void)
{
	struct timeval	tv;
	long			now;

	gettimeofday(&tv, NULL);
	now = (tv.tv_sec * 1000) + (tv.tv_usec * 0.001);
	return (now);
}

// The 25 microseconds allow the "over_mutex" to be freed long enough for
// all threads to use it.
void	ft_wait(long msec, t_data *data)
{
	long	start_time;

	start_time = now();
	pthread_mutex_lock(&data->over_mtx);
	while ((now() - start_time < msec) && !data->over)
	{
		pthread_mutex_unlock(&data->over_mtx);
		usleep(25);
		pthread_mutex_lock(&data->over_mtx);
	}
	pthread_mutex_unlock(&data->over_mtx);
}

int	ft_error(char *str)
{
	int	i;

	write(2, "ERROR: ", 7);
	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
	return (EXIT_FAILURE);
}
