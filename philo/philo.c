/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 23:23:19 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/28 14:30:01 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

/*
Despues de pthread_create hay que asegurarse de liberar los recursos usados
por el propio sistema y para ello, el thread debe haber finalizado.

Si usamos pthread_join para esperar a que termine, la propia pthred_join
libera la memoria.
 
Si finaliza el thread de otra forma que no sea usando pthread_join entonces
debemos liberarlos expresamente con pthread_detach
*/
int	main(int argc, char *argv[])
{
	t_data			data;
	t_philo			*philo;

	if (args_parse(argc, argv))
		return (EXIT_FAILURE);
	if (data_load(&data, argc, argv))
		return (EXIT_FAILURE);
	if (philos_create(&data, &philo))
		return (EXIT_FAILURE);
	controller(&data, &philo);
	free (data.fork);
	free (data.black_holes);
	free (philo);
	return (EXIT_SUCCESS);
}
