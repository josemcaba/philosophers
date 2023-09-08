/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:35:48 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/08 13:49:15 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

typedef struct s_data
{
	int				nbr_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				min_meals;
	long			start_time;
	sem_t			*forks_sem;
	int				full_philos;
	pthread_mutex_t	full_philos_mtx;
	int				over;
	pthread_mutex_t	over_mtx;
	pthread_mutex_t	print_mtx;
}	t_data;

typedef struct s_philo
{
	t_data				*data;
	int					id;
	int					nbr_meals;
	long				now;
	long				black_hole;
	pthread_mutex_t		black_hole_mtx;
	pthread_t			th_id;
}	t_philo;

int		data_init(t_data *data, int argc, char *argv[]);
int		philos_init(t_data *data, t_philo **philo);
int		philos_create(t_data *data, t_philo **philos);
void	controller(t_data *data, t_philo **philo);
void	mutexes_destroy(t_data *data, t_philo **philos, int nbr);
void	philos_destroy(t_data *data, t_philo **philos, int nbr);
long	now(void);
void	ft_wait(long msec, t_data *data);
int		random_0_9(int min, int max);
void	print_state(char *str, t_philo *philo);
void	thinking(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
int		error(char *str);

#endif
