/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:48:05 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/27 11:48:14 by jocaball         ###   ########.fr       */
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

int	data_load(t_data *data, int argc, char *argv[])
{
	data->n_philos = ft_atoi(argv[1]);
	if (!data->n_philos)
	{
		ft_putstr_fd("ERROR: Invalid number of philosophers\n", 2);
		return (EXIT_FAILURE);
	}
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->n_meals = -1;
	data->one_death = 0;
	if (argc == 6)
		data->n_meals = ft_atoi(argv[5]);
	data->forks = malloc(data->n_philos * sizeof(char));
	if (!data->forks)
	{
		ft_putstr_fd("ERROR: Can not allocate memory for forks\n", 2);
		return (EXIT_FAILURE);
	}
	memset(data->forks, 0, data->n_philos * sizeof(char));
	return (EXIT_SUCCESS);
}
