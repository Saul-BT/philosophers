/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblanco- <sblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:03:15 by sblanco-          #+#    #+#             */
/*   Updated: 2024/06/16 14:40:16 by sblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_fork(int id, t_fork *fork)
{
	fork->id = id;
	fork->mutex = mutex_create();
}

static void	init_forkless_philo(int id, t_philo *philo)
{
	philo->id = id;
	philo->eat_count = 0;
	philo->last_eat_time = 0;
}

void	init_data(t_table *table)
{
	int	i;

	i = 0;
	table->forks = secure_malloc(sizeof(t_fork) * table->philo_count);
	table->philos = secure_malloc(sizeof(t_philo) * table->philo_count);
	while (i < table->philo_count)
	{
		init_fork(i, &table->forks[i]);
		init_forkless_philo(i, &table->philos[i]);
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1)
			% table->philo_count];
		i++;
	}
}
