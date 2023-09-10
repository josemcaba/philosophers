/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 23:23:19 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/10 23:12:34 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data			data;

	if (data_init(&data, argc, argv))
		return (EXIT_FAILURE);
	if (philos_init(&data))
		return (EXIT_FAILURE);
	// if (philos_create(&data))
	// 	return (EXIT_FAILURE);
	// controller(&data, &philos);
	return (EXIT_SUCCESS);
}
