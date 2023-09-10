/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 23:23:19 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/10 14:43:43 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data			data;
	t_philo			*philos;

	if (data_init(&data, argc, argv))
		return (EXIT_FAILURE);
	if (philos_init(&data, &philos))
		return (EXIT_FAILURE);
	printf("BIEN\n");
	// if (philos_create(&data, &philos))
	// 	return (EXIT_FAILURE);
	// controller(&data, &philos);
	return (EXIT_SUCCESS);
}
