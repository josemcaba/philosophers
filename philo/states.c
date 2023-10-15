/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 09:42:01 by jocaball          #+#    #+#             */
/*   Updated: 2023/10/15 13:02:55 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mtx);
	philo->now = now();
	pthread_mutex_lock(&philo->data->over_mtx);
	if (!philo->data->over)
		printf("%06ld %d %s\n", philo->now - philo->data->start_time, \
				philo->id, str);
	pthread_mutex_unlock(&philo->data->over_mtx);
	pthread_mutex_unlock(&philo->data->print_mtx);
}

void	thinking(t_philo *philo)
{
	print_state("is thinking", philo);
	ft_wait(philo->data->time_to_eat * 0.01, philo->data);
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
	philo->black_hole = philo->now + philo->data->time_to_die;
	pthread_mutex_unlock(&philo->black_hole_mtx);
	ft_wait(philo->data->time_to_eat, philo->data);
	if (philo->data->min_nbr_meals > 0)
	{
		if (++philo->nbr_meals == philo->data->min_nbr_meals)
		{
			pthread_mutex_lock(&philo->data->nbr_full_philos_mtx);
			philo->data->nbr_full_philos++;
			pthread_mutex_unlock(&philo->data->nbr_full_philos_mtx);
		}
	}
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleeping(t_philo *philo)
{
	print_state("is sleeping", philo);
	ft_wait(philo->data->time_to_sleep, philo->data);
}
