/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:48:05 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/31 09:54:13 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

int	error(char *str)
{
	int	i;

	write(2, "ERROR: ", 7);
	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
	return (EXIT_FAILURE);
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
		return (error("Numbers must be int\n") * -2);
	return (number);
}

static int	data_mutex_init(t_data *data)
{
	if (pthread_mutex_init(&data->full_philos_mtx, NULL))
		return (error("Can not init mutex for full_philos\n"));
	if (pthread_mutex_init(&data->over_mtx, NULL))
		return (error("Can not init mutex for over\n"));
	if (pthread_mutex_init(&data->print_mtx, NULL))
		return (error("Can not init mutex for print_status\n"));
	return (EXIT_SUCCESS);
}

static int	args_parse(int argc, char *argv[])
{
	int	i;
	int	j;

	if ((argc != 5) && (argc != 6))
		return (error("Wrong number of parameters\n"));
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if ((argv[i][j] < '0') || (argv[i][j] > '9'))
				return (error("Invalid parameters, positive numbers only\n"));
	}
	return (EXIT_SUCCESS);
}

int	data_init(t_data *data, int argc, char *argv[])
{
	if (args_parse(argc, argv))
		return (EXIT_FAILURE);
	data->nbr_philos = ft_atoi(argv[1]);
	if (!data->nbr_philos)
		return (error("There is no philosopher\n"));
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->min_meals = -1;
	if (argc == 6)
		data->min_meals = ft_atoi(argv[5]);
	if (data->min_meals == 0)
		return (error("Philosophers would like to eat something\n"));
	if (data->nbr_philos < 0 || data->time_die < 0 || \
		data->time_eat < 0 || data->time_sleep < 0 || \
		data->min_meals < -1)
		return (EXIT_FAILURE);
	data->full_philos = 0;
	data->over = 0;
	if (data_mutex_init(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
