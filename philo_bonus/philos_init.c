/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:17:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/11 00:58:40 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_create(t_philo *philo)
{
	philo->black_hole_sem = sem_open("/hole", O_CREAT, 400, 1);
	if (philo->black_hole_sem == SEM_FAILED)
	{
		ft_error("Can not open /hole semaphore\n");
		exit (1);
	}
	philo->black_hole = now() + philo->data->time_die;
	// while (!philo->data->over)
	// {
		thinking(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
		eating(philo);
		sleeping(philo);
	// }
	exit (0);
}

int	philos_init(t_data *data)
{
	int		i;
	t_philo	philo;

	data->pid_philo = malloc(data->nbr_philos * sizeof(pid_t) + 1);
	if (!data->pid_philo)
		return (ft_error("Can not allocate memory for philosophers PIDs\n"));
	data->start_time = now();
	i = 0;
	while (++i <= data->nbr_philos)
	{
		philo.data = data;
		philo.id = i;
		philo.nbr_meals = 0;
		data->pid_philo[i] = fork();
		if (data->pid_philo[i] == 0)
			philo_create(&philo);
	}
	ft_wait(data->time_die, data);
	return (EXIT_SUCCESS);
}
