/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:36:32 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/04 00:16:23 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutexes_destroy(t_data *data, t_philo **philos, int nbr)
{
	int	i;

	pthread_mutex_lock(&data->over_mtx);
	data->over = 1;
	pthread_mutex_unlock(&data->over_mtx);
	i = -1;
	while (++i < nbr)
	{
		pthread_mutex_destroy(&(*philos)[i].black_hole_mtx);
		pthread_mutex_destroy(&(*philos)[i].right_fork_mtx);
	}
}

/*
Se fuerza la finalización de la cena y se espera a que finalicen los 
filosofos ya creados. El numero de filosofos creados viene dado en el
parametro nbr. 
*/
void	philos_destroy(t_data *data, t_philo **philos, int nbr)
{
	int	i;

	pthread_mutex_lock(&data->over_mtx);
	data->over = 1;
	pthread_mutex_unlock(&data->over_mtx);
	i = -1;
	while (++i < nbr)
		pthread_join((*philos)[i].th_id, NULL);
}
