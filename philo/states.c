/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 09:42:01 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/27 09:56:04 by jocaball         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <philo.h>

// Está pensando mientras intenta conseguir un tenedor
void	think (t_philo	*philo)
{
	while (!philo->left && !philo->right)
	{
		philo->left = 1;
		philo->right = 1;
	}
}

void	eat (t_philo *philo)
{
	philo
}
