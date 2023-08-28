/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:35:48 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/28 14:17:27 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
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
	pthread_mutex_t	*fork;
	int				dinner_is_over;
	long			*black_holes;
	pthread_mutex_t	ctrl_mtx;
}	t_data;

typedef struct s_philo
{
	int					id;
	int					nbr_meals;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_t			th_id;
	t_data				*data;
}	t_philo;

int		args_parse(int argc, char *argv[]);
int		data_load(t_data *data, int argc, char *argv[]);
void	ft_putstr_fd(char *str, int fd);
int		now_time(long *now);
long	delta_time(long time);
int		philos_create(t_data *data, t_philo **philo);
void	philos_detach(t_philo **philo);
void	thinking (t_philo *philo);
void	eating (t_philo *philo);
void	sleeping (t_philo *philo);
void	controller(t_data *data, t_philo **philo);

#endif
