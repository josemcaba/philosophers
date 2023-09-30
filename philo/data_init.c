/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:48:05 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/30 21:13:27 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// The dummy_fork will always be locked. It is used when there is only one
// philosopher, since he will try to pick up the fork on his left.
static int	data_mutex_init(t_data *data)
{
	if (pthread_mutex_init(&data->nbr_full_philos_mtx, NULL))
		return (ft_error("Can not init mutex for nbr_full_philos\n"));
	if (pthread_mutex_init(&data->over_mtx, NULL))
		return (ft_error("Can not init mutex for over\n"));
	if (pthread_mutex_init(&data->print_mtx, NULL))
		return (ft_error("Can not init mutex for print status\n"));
	if (pthread_mutex_init(&data->dummy_fork, NULL))
		return (ft_error("Can not init dummy_fork mutex\n"));
	pthread_mutex_lock(&data->dummy_fork);
	return (EXIT_SUCCESS);
}

static int	ft_atoi(const char *str)
{
	size_t	number;

	while (((*str >= '\t') && (*str <= '\r')) || (*str == ' '))
		str++;
	number = 0;
	while ((*str >= '0') && (*str <= '9'))
	{
		number = (number * 10) + *str - '0';
		str++;
	}
	if (number > 0x7fffffff)
		return (ft_error("The numbers must be integers (int)\n") * -2);
	return (number);
}

int	data_init(t_data *data, int argc, char *argv[])
{
	data->nbr_philos = ft_atoi(argv[1]);
	if (!data->nbr_philos)
		return (ft_error("There is no philosopher\n"));
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->min_nbr_meals = -1;
	if (argc == 6)
		data->min_nbr_meals = ft_atoi(argv[5]);
	if (data->min_nbr_meals == 0)
		return (ft_error("Philosophers would like to eat something\n"));
	data->nbr_full_philos = 0;
	data->over = 0;
	data->start_time = 0;
	if (data_mutex_init(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
