/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblanco- <sblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:16:49 by sblanco-          #+#    #+#             */
/*   Updated: 2024/06/16 13:25:31 by sblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAFE_H
# define SAFE_H

# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
	bool			is_created;
}					t_mutex;

// From alloc.c
void				*secure_malloc(size_t size);

// From util.c
void				exit_error(char *msg);

// From mutex.c
void				mutex_init(void);
void				mutex_destroy(t_mutex *mutex);
void				mutex_lock(t_mutex *mutex);
void				mutex_unlock(t_mutex *mutex);

// From thread.c
pthread_t			thread_create(void *(*routine)(void *), void *arg);
void				thread_join(pthread_t thread);

#endif