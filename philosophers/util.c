/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblanco- <sblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:43:31 by sblanco-          #+#    #+#             */
/*   Updated: 2024/06/16 20:22:35 by sblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_message(t_philo philo, char *message)
{
	mutex_lock(philo.table->print_mutex);
	printf("%ld: %d %s\n", get_time(), philo.id, message);
	mutex_unlock(philo.table->print_mutex);
}
