/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:30:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/26 19:03:07 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

int	now_time(long *now)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		ft_putstr_fd("ERROR: Can not get the time\n", 2);
		return (EXIT_FAILURE);
	}
	*now = (tv.tv_sec * 1000) + (tv.tv_usec * 0.001);
	return (EXIT_SUCCESS);
}

long	delta_time(long time)
{
	long	now;

	if (now_time(&now))
		return (-1);
	return (now - time);
}
