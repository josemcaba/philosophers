/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 09:42:01 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/28 22:39:10 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

// #include "philo.h"

// void	print_status(char *str, t_philo *philo, long *now)
// {
// 	pthread_mutex_lock(&philo->data->ctrl_mtx);
// 	*now = 0;
// 	if (!philo->data->dinner_is_over)
// 	{
// 		now_time(now);
// 		printf("%ld %d %s\n", *now, philo->id, str);
// 	}
// 	pthread_mutex_unlock(&philo->data->ctrl_mtx);
// }

// // Está pensando mientras intenta conseguir los tenedores
// void	thinking (t_philo *philo)
// {
// 	long	now;

// 	print_status("is thinking", philo, &now);
// 	while (!philo->left_fork && !philo->right_fork)
// 	{
// 		if (philo->data->dinner_is_over)
// 			return ;
// 		philo->left_fork = (pthread_mutex_t *)1;
// 		philo->right_fork = (pthread_mutex_t *)1 ;
// 	}
// 	print_status("has taken a fork", philo, &now);
// }

// void	eating (t_philo *philo)
// {
// 	long	now;

// 	print_status("is eating", philo, &now);
// 	philo->data->black_holes[philo->id - 1] = now + philo->data->time_die;
// 	while (delta_time(now) < philo->data->time_eat)
// 		if (philo->data->dinner_is_over)
// 			return ;
// 	if (philo->data->min_meals >= 0)
// 	{
// 		philo->nbr_meals++;
// 	}
// 	philo->left_fork = NULL;
// 	philo->right_fork = NULL;
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
