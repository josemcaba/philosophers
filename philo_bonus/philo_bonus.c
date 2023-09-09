/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:54:53 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/09 18:37:23 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	philos;
	
	pid_t	pid;
	int		status;

	printf("Soy el Controller ");
	if (data_init(&data, argc, argv))
		return (EXIT_FAILURE);
	
	if (philos_init(&data, &philos))
		return (EXIT_FAILURE);
		
	pid = fork();
	if (pid == 0)
	{
		printf("\nSoy el hijo ...\n");
		usleep(3000000);
		printf("... y he terminado\n");
		exit(0);
	}
//	else
//	{
		printf("Mi hijo es el %d\n", pid);
		printf("Estoy esperando a que mi hijo termine ...\n");
		waitpid(pid, &status, 0);
		printf("\nMi hijo ha terminado\n");
//	}
	
	return (0);
}
