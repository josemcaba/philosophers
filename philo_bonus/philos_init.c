/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:17:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/10 14:59:09 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philos_sem_init(t_philo *philo)
{
	//sem_unlink("/hole");
	philo->black_hole_sem = sem_open("/hole", O_CREAT | O_EXCL, 400, 1);
	if (philo->black_hole_sem == SEM_FAILED)
		return (ft_error("Can not open /hole semaphore\n"));	
	return (EXIT_SUCCESS);
}

int	philos_init(t_data *data, t_philo **philos)
{
	int	i;

	*philos = malloc(data->nbr_philos * sizeof(t_philo));
	if (!(*philos))
		return (ft_error("Can not allocate memory for philosophers\n"));
	i = -1;
	while (++i < data->nbr_philos)
	{
		(*philos)[i].data = data;
		(*philos)[i].id = i + 1;
		(*philos)[i].nbr_meals = 0;
		if (philos_sem_init(&(*philos)[i]))
		{
			philos_destroy(data, philos, 0);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
