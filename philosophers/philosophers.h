/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblanco- <sblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 09:22:36 by sblanco-          #+#    #+#             */
/*   Updated: 2024/06/16 14:02:14 by sblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "safe/safe.h"
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef long			t_us;

typedef struct s_fork	t_fork;
typedef struct s_philo	t_philo;
typedef struct s_table	t_table;

struct					s_table
{
	int					max_eat_count;
	int					philo_count;
	t_us				time_to_die;
	t_us				time_to_eat;
	t_us				time_to_sleep;
	t_philo				*philos;
	t_fork				*forks;
};

struct					s_fork
{
	int					id;
	t_mutex				*mutex;
};

struct					s_philo
{
	int					id;
	int					eat_count;
	t_us				last_eat_time;
	t_fork				*left_fork;
	t_fork				*right_fork;
	pthread_t			thread;
};

void					parse_input(int argc, char **args, t_table *table);

#endif
