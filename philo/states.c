/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 09:42:01 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/29 02:22:48 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

void	print_state(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->finish_mtx);
	if (philo->data->finish)
	{
		pthread_mutex_unlock(&philo->data->finish_mtx);
		return ;
	}
	pthread_mutex_lock(&philo->data->print_mtx);
	printf("%ld %d %s\n", now(), philo->id, str);
	pthread_mutex_unlock(&philo->data->print_mtx);
}

// Está pensando mientras intenta conseguir los tenedores
void	thinking (t_philo *philo)
{
	print_state("is thinking", philo);
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->right_fork);
		print_state("has taken a fork", philo);
		pthread_mutex_lock(philo->left_fork);
		print_state("has taken a fork", philo);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_state("has taken a fork", philo);
		pthread_mutex_lock(&philo->right_fork);
		print_state("has taken a fork", philo);		
	}
}

// void	eating (t_philo *philo)
// {
// 	long	now;

// 	print_state("is eating", philo, &now);
// 	philo->data->black_holes[philo->id - 1] = now() + philo->data->time_die;
// 	while (delta_time(now) < philo->data->time_eat)
// 		if (philo->data->dinner_is_over)
// 			return ;
// 	if (philo->data->min_meals >= 0)
// 	{
// 		philo->nbr_meals++;
// 	}
// 	pthread_mutex_unlock(&philo->right_fork);
// 	pthread_mutex_unlock(philo->left_fork);
// }

// void	sleeping (t_philo *philo)
// {
// 	long 	now;
// 	long	delta;
	
// 	print_status("is sleeping", philo, &now);
// 	delta = delta_time(now);
// 	while (delta < philo->data->time_sleep && 
//  			!philo->data->dinner_is_over)
// 	{
// 		printf("%ld\n", philo->data->black_holes[philo->id]);
// 		if (philo->data->black_holes[philo->id] && 
// 			now + delta >= philo->data->black_holes[philo->id])
// 		{
// 			print_status("died sleeping", philo, &now);
// 			philo->data->dinner_is_over = philo->id;
// 			return ;
// 		}
// 		delta = delta_time(now);
// 	}
// }
