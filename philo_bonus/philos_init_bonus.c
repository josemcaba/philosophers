/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:17:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/08 21:38:59 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philos_init(t_data *data, t_philo **philos)
{
	int	i;

	*philos = malloc(data->nbr_philos * sizeof(t_philo));
	if (!(*philos))
		return (error("Can not allocate memory for philosophers\n"));
	i = -1;
	while (++i < data->nbr_philos)
	{
		(*philos)[i].data = data;
		(*philos)[i].id = i + 1;
		(*philos)[i].nbr_meals = 0;
	}
	return (EXIT_SUCCESS);
}
