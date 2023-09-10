/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:48:05 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/11 00:26:49 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	data_sem_open(t_data *data)
{
	sem_unlink("/forks");
	data->forks_sem = sem_open("/forks", O_CREAT | O_EXCL, 400, \
								data->nbr_philos);
	if (data->forks_sem == SEM_FAILED)
		return (ft_error("Can not open /forks semaphore\n"));
	sem_unlink("/over");
	data->over_sem = sem_open("/over", O_CREAT | O_EXCL, 400, 1);
	if (data->over_sem == SEM_FAILED)
		return (ft_error("Can not open /over semaphore\n"));
	sem_unlink("/print");
	data->print_sem = sem_open("/print", O_CREAT | O_EXCL, 400, 1);
	if (data->print_sem == SEM_FAILED)
		return (ft_error("Can not open /print semaphore\n"));
    if (data->min_meals > 0)
	{		
		sem_unlink("/full");
		data->full_sem = sem_open("/full", O_CREAT | O_EXCL, 400, \
									data->min_meals);
		if (data->full_sem == SEM_FAILED)
			return (ft_error("Can not open /full semaphore\n"));
	}
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
		return (ft_error("Numbers must be int\n") * -2);
	return (number);
}

static int	args_parse(int argc, char *argv[])
{
	int	i;
	int	j;

	if ((argc != 5) && (argc != 6))
		return (ft_error("Wrong number of parameters\n"));
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if ((argv[i][j] < '0') || (argv[i][j] > '9'))
				return (ft_error("Invalid parameters, positive numbers only\n"));
	}
	return (EXIT_SUCCESS);
}

int	data_init(t_data *data, int argc, char *argv[])
{
	if (args_parse(argc, argv))
		return (EXIT_FAILURE);
	data->nbr_philos = ft_atoi(argv[1]);
	if (!data->nbr_philos)
		return (ft_error("There is no philosopher\n"));
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->start_time = 0;
	data->min_meals = -1;
	if (argc == 6)
		data->min_meals = ft_atoi(argv[5]);
	if (data->min_meals == 0)
		return (ft_error("Philosophers would like to eat something\n"));
	if (data->nbr_philos < 0 || data->time_die < 0 || \
		data->time_eat < 0 || data->time_sleep < 0 || \
		data->min_meals < -1)
		return (EXIT_FAILURE);
	data->full_philos = 0;
	data->over = 0;
	if (data_sem_open(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
