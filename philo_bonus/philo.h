/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:35:48 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/10 14:40:25 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <semaphore.h>

typedef struct s_data
{
	int		nbr_philos;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		min_meals;
	long	start_time;
	sem_t	*forks_sem;
	int		full_philos;
	sem_t	*full_sem;
	int		over;
	sem_t	*over_sem;
	sem_t	*print_sem;
}	t_data;

typedef struct s_philo
{
	t_data	*data;
	int		id;
	int		nbr_meals;
	long	now;
	long	black_hole;
	sem_t	*black_hole_sem;
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
