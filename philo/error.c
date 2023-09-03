/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:53:52 by jocaball          #+#    #+#             */
/*   Updated: 2023/09/03 11:55:58 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *str)
{
	int	i;

	write(2, "ERROR: ", 7);
	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
	return (EXIT_FAILURE);
}
