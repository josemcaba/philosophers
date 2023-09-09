/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:17:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/09 18:13:04 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_create(t_data *data, t_philo *philo)
{
	data->start_time = now();
	philo->black_hole = now() + data->time_die;
	while (!philo->data->over)
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
}

int	philos_init(t_data *data, t_philo *philo)
{
	int		i;
	pid_t	pid;

	i = -1;
	while (++i < data->nbr_philos)
	{
		philo->data = data;
		philo->id = i + 1;
		philo->nbr_meals = 0;
		pid = fork();
		if (pid == 0)
		{
			philo_create(data, philo);
			exit(0);
		}
	}
	return (EXIT_SUCCESS);
}
