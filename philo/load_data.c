/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:51:03 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/26 15:12:44 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

static void	*ft_calloc(int count, int size)
{
	char	*ptr;
	int		total_size;

	total_size = count * size;
	ptr = (char *)malloc(total_size);
	if (!ptr)
		return (0);
	memset(ptr, 0, total_size);
	return ((void *)ptr);
}

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

int	load_data(t_data *data, int argc, char *argv[])
{
	data->n_philo = ft_atoi(argv[1]);
	if (!data->n_philo)
	{
		ft_putstr_fd("ERROR: Invalid number of philosophers\n", 2);
		return (NOK);
	}
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->n_meals = -1;
	if (argc == 6)
		data->n_meals = ft_atoi(argv[5]);
	data->forks = ft_calloc(data->n_philo, sizeof(char));
	if (!data->forks)
	{
		ft_putstr_fd("ERROR: Can not allocate memory for forks\n", 2);
		return (NOK);
	}
	return (OK);
}
