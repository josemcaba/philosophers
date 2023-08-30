/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 23:23:19 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/30 21:06:54 by jocaball         ###   ########.fr       */
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
	t_philo			*philos;

	if (data_init(&data, argc, argv))
		return (EXIT_FAILURE);
	if (philos_init(&data, &philos))
		return (EXIT_FAILURE);
	controller(&data, &philos);
	free (philos);
	return (EXIT_SUCCESS);
}
