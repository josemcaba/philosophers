/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 09:42:01 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/27 14:52:51 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

// Está pensando mientras intenta conseguir los tenedores
void	thinking (t_philo *philo)
{
	long now;
	
	if (philo->data->one_death)
		return ;
	now_time(&now);
	printf("%ld %d is thinking\n", now, philo->id);
	while (!philo->left && !philo->right)
	{
		if (philo->data->one_death)
			return ;
		*philo->left = 1;
		*philo->right = 1;
	}
	printf("%ld %d has taken a fork\n", now, philo->id);
}

void	eating (t_philo *philo)
{
	long now;
	
	if (philo->data->one_death)
		return ;
	now_time(&now);	
	philo->data->black_holes[philo->id - 1] = now + philo->data->t_die;
	printf("%ld %d is eating\n", now, philo->id);
	while (delta_time(now) < philo->data->t_eat)
		if (philo->data->one_death)
			return ;
	if (philo->data->n_meals >= 0)
	{
		philo->meals++;
	}
	*philo->left = 0;
	*philo->right = 0;
}

void	sleeping (t_philo *philo)
{
	long now;
	
	if (philo->data->one_death)
		return ;
	now_time(&now);
	printf("%ld %d is sleeping\n", now, philo->id);
	while (delta_time(now) < philo->data->t_sleep)
		if (philo->data->one_death)
			return ;
}
