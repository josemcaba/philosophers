/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:35:48 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/30 21:25:23 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
	int				nbr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				min_nbr_meals;
	int				nbr_full_philos;
	pthread_mutex_t	nbr_full_philos_mtx;
	int				over;
	pthread_mutex_t	over_mtx;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	dummy_fork;
	long			start_time;
}	t_data;

typedef struct s_philo
{
	t_data				*data;
	int					id;
	int					nbr_meals;
	long				now;
	long				black_hole;
	pthread_mutex_t		black_hole_mtx;
	pthread_mutex_t		right_fork;
	pthread_mutex_t		*left_fork;
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
void	print_state(char *str, t_philo *philo);
void	thinking(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
int		ft_error(char *str);

#endif
