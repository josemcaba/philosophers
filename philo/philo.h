/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:35:48 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/26 15:00:28 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

# define OK 1
# define NOK 0

typedef struct s_data
{
	int		n_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		n_meals;
	char	*forks;
	int		error;
}	t_data;

typedef struct s_philo
{
	int	id;
	int	last_eat;
	int	n_eat;
}	t_philo;

int		parser(int argc, char *argv[]);
int		load_data(t_data *data, int argc, char *argv[]);
void	ft_putstr_fd(char *str, int fd);

#endif
