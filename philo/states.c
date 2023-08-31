/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 09:42:01 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/31 13:05:19 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
The 10 microseconds are to ensure that, in case dinner is over, 
nothing is printed and that the philosophers do not move on to
the next state.
*/
void	print_state(char *str, t_philo *philo)
{
	usleep(10);
	pthread_mutex_lock(&philo->data->over_mtx);
	pthread_mutex_lock(&philo->data->print_mtx);
	if (!philo->data->over)
		printf("%ld %d %s\n", now(), philo->id, str);
	pthread_mutex_unlock(&philo->data->print_mtx);
	pthread_mutex_unlock(&philo->data->over_mtx);
}

void	thinking(t_philo *philo)
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

void	eating(t_philo *philo)
{
	print_state("is eating", philo);
	pthread_mutex_lock(&philo->black_hole_mtx);
	philo->black_hole = now() + philo->data->time_die;
	pthread_mutex_unlock(&philo->black_hole_mtx);
	wait(philo->data->time_eat, philo);
	if (philo->data->min_meals > 0)
	{
		if (++philo->nbr_meals == philo->data->min_meals)
		{
			pthread_mutex_lock(&philo->data->full_philos_mtx);
			philo->data->full_philos++;
			pthread_mutex_unlock(&philo->data->full_philos_mtx);
		}
	}
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleeping(t_philo *philo)
{
	print_state("is sleeping", philo);
	wait(philo->data->time_sleep, philo);
}
