/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   now_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:30:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/26 14:50:19 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

int	now_time(long *n)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		ft_putstr_fd("ERROR: Can not get the time\n", 2);
		return (-1);
	}
	*n = (tv.tv_sec * 1000) + (tv.tv_usec * 0.001);
	return (0);
}
