/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:17:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/08 22:42:43 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philos_mutex_init(t_philo *philo)
{
	if (pthread_mutex_init(&(*philo).black_hole_mtx, NULL))
		return (error("Can not init black_hole mutex\n"));
	if (pthread_mutex_init(&(*philo).right_fork, NULL))
		return (error("Can not init right_fork mutex\n"));
	if (pthread_mutex_init(&(*philo).data->dummy_fork, NULL))
		return (error("Can not init dummy_fork mutex\n"));
	pthread_mutex_lock(&(*philo).data->dummy_fork);
	return (EXIT_SUCCESS);
}

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
		if (philos_mutex_init(&(*philos)[i]))
		{
			free(*philos);
			return (EXIT_FAILURE);
		}
		if (i > 0)
			(*philos)[i].left_fork = &(*philos)[i - 1].right_fork;
	}
	if (data->nbr_philos == 1)
		(*philos)[0].left_fork = &data->dummy_fork;
	else
		(*philos)[0].left_fork = &(*philos)[data->nbr_philos - 1].right_fork;
	return (EXIT_SUCCESS);
}
