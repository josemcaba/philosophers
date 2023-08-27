/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:48:05 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/27 00:52:14 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

int	args_parse(int argc, char *argv[])
{
	int	i;
	int	j;

	if ((argc != 5) && (argc != 6))
	{
		ft_putstr_fd("ERROR: Wrong number of parameters\n", 2);
		return (EXIT_FAILURE);
	}
	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0') || (argv[i][j] > '9'))
			{
				ft_putstr_fd("ERROR: Parameter \"", 2);
				ft_putstr_fd(argv[i], 2);
				ft_putstr_fd("\" is invalid\n", 2);
				return (EXIT_FAILURE);
			}
			j++;
		}
	}
	return (EXIT_SUCCESS);
}
