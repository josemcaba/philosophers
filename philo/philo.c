/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 23:23:19 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/26 14:58:43 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!parser(argc, argv))
		return (EXIT_FAILURE);
	if (!load_data(&data, argc, argv))
		return (EXIT_FAILURE);
	free (data.forks);
	return (EXIT_SUCCESS);
}
