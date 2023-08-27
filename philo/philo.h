/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:35:48 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/27 02:07:31 by jocaball         ###   ########.fr       */
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
	int			n_philos;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			n_meals;
	char		*forks;
	int			error;
}	t_data;

typedef struct s_philo
{
	int			id;
	long		t_last_eat;
	int			meals;
	char		*left;
	char		*right;
	pthread_t	th_id;
	t_data		*data;
}	t_philo;

int		args_parse(int argc, char *argv[]);
int		data_load(t_data *data, int argc, char *argv[]);
void	ft_putstr_fd(char *str, int fd);
int		now_time(long *now);
long	delta_time(long time);
int		philos_create(t_data *data, t_philo **philo);
void	philos_detach(t_philo **philo);

#endif
