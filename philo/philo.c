/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 23:23:19 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/30 22:32:31 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	args_parse(int argc, char *argv[])
{
	int	i;
	int	j;

	if ((argc != 5) && (argc != 6))
		return (ft_error("Wrong number of arguments\n"));
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if ((argv[i][j] < '0') || (argv[i][j] > '9'))
				return (ft_error("Invalid argument, only digits allowed\n"));
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_data			data;
	t_philo			*philos;

	if (args_parse(argc, argv))
		return (EXIT_FAILURE);
	if (data_init(&data, argc, argv))
		return (EXIT_FAILURE);
	if (philos_init(&data, &philos))
		return (EXIT_FAILURE);
	if (philos_create(&data, &philos))
		return (EXIT_FAILURE);
	controller(&data, &philos);
	return (EXIT_SUCCESS);
}
