/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:48:05 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/28 14:49:25 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

static int	ft_atoi(const char *str)
{
	int	number;

	number = 0;
	while (*str)
	{
		number = (number * 10) + *str - '0';
		str++;
	}
	return (number);
}

int	forks_load(t_data *data)
{
	data->fork = malloc(data->nbr_philos * sizeof(pthread_mutex_t));
	if (!data->fork)
	{
		ft_putstr_fd("ERROR: Can not allocate memory for forks\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	black_holes_load(t_data *data)
{
	int	i;

	data->black_holes = malloc(data->nbr_philos * sizeof(long));
	if (!data->black_holes)
	{
		ft_putstr_fd("ERROR: Can not allocate memory for black_holes\n", 2);
		return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < data->nbr_philos)
		data->black_holes[i] = 0x7fffffffffffffff;
	return (EXIT_SUCCESS);
}

int	data_load(t_data *data, int argc, char *argv[])
{
	data->nbr_philos = ft_atoi(argv[1]);
	if (!data->nbr_philos)
	{
		ft_putstr_fd("ERROR: Invalid number of philosophers\n", 2);
		return (EXIT_FAILURE);
	}
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->min_meals = -1;
	data->dinner_is_over = 0;
	if (argc == 6)
		data->min_meals = ft_atoi(argv[5]);
	if (!data->min_meals)
	{
		ft_putstr_fd("ERROR: Invalid number of times must eat\n", 2);
		return (EXIT_FAILURE);
	}
	if (forks_load(data))
		return (EXIT_FAILURE);
	if (black_holes_load(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
