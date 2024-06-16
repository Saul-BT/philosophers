/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblanco- <sblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:48:17 by sblanco-          #+#    #+#             */
/*   Updated: 2024/06/16 20:18:15 by sblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_eat(t_philo *philo)
{
	mutex_lock(philo->left_fork->mutex);
	print_message(*philo, "has taken the left fork 🍴");
	mutex_lock(philo->right_fork->mutex);
	print_message(*philo, "has taken the right fork 🍴");
	philo->eat_count++;
	print_message(*philo, "is eating 🍜");
	wait(philo->table->time_to_eat);
	philo->last_eat_time = get_time();
	mutex_unlock(philo->left_fork->mutex);
	mutex_unlock(philo->right_fork->mutex);
}

static void	philo_sleep(t_philo *philo)
{
	print_message(*philo, "is sleeping 💤");
	wait(philo->table->time_to_sleep);
}

static void	philo_think(t_philo *philo)
{
	print_message(*philo, "is thinking 🧠");
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	table = philo->table;
	while (true)
	{
		if (get_time() - philo->last_eat_time >= table->time_to_die)
		{
			philo->alive = false;
			break ;
		}
		if (table->max_eat_count != -1
			&& philo->eat_count >= table->max_eat_count)
			break ;
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	start_hunger_game(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < table->philo_count)
	{
		philo = &table->philos[i];
		philo->thread = thread_create(philo_routine, philo);
		i++;
	}
	i = 0;
	while (i < table->philo_count)
	{
		philo = &table->philos[i];
		thread_join(philo->thread);
		i++;
	}
	i = 0;
	while (i < table->philo_count)
	{
		philo = &table->philos[i];
		mutex_destroy(philo->left_fork->mutex);
		philo->left_fork->mutex = NULL;
		mutex_destroy(philo->right_fork->mutex);
		philo->right_fork->mutex = NULL;
		i++;
	}
	mutex_destroy(table->print_mutex);
}
