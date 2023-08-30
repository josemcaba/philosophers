/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:35:48 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/30 14:52:06 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				min_meals;
	int				full_philos;
	pthread_mutex_t	full_philos_mtx;
	int				finish;
	pthread_mutex_t	finish_mtx;
	pthread_mutex_t	print_mtx;
}	t_data;

typedef struct s_philo
{
	t_data				*data;
	int					id;
	int					nbr_meals;
	long				black_hole;
	pthread_mutex_t		black_hole_mtx;
	pthread_mutex_t		right_fork;
	pthread_mutex_t		*left_fork;
	pthread_t			th_id;
}	t_philo;

int		data_init(t_data *data, int argc, char *argv[]);
int		error(char *str);
long	now(void);
void	wait(long msec, t_philo *philo);
void	print_state(char *str, t_philo *philo);
int		philos_create(t_data *data, t_philo **philo);
void	thinking (t_philo *philo);
void	eating (t_philo *philo);
void	sleeping (t_philo *philo);
void	controller(t_data *data, t_philo **philo);

#endif
