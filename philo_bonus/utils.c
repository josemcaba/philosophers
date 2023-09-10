/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:30:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/10 14:07:47 by jocaball         ###   ########.fr       */
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

/*
The 50 microseconds allow the "over_mutex" to be freed long enough for
all threads to use it.
*/
void	ft_wait(long msec, t_data *data)
{
	long	start_time;

	start_time = now();
	sem_wait(data->over_sem);
	while ((now() - start_time < msec) && !data->over)
	{
		sem_post(data->over_sem);
		usleep(50);
		sem_wait(data->over_sem);
	}
	sem_post(data->over_sem);
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
