/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblanco- <sblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:16:12 by sblanco-          #+#    #+#             */
/*   Updated: 2024/06/16 19:39:19 by sblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safe.h"

/**
 * \brief		Create a thread safely
 * \param[in]	routine: The thread routine
 * \param[in]	arg: The argument to pass to the thread routine
 * \return		The thread id
 */
pthread_t	thread_create(void *(*routine)(void *), void *arg)
{
	pthread_t	thread;

	if (!!pthread_create(&thread, NULL, routine, arg))
		exit_error("pthread_create");
	return (thread);
}

/**
 * \brief		Join a thread safely
 * \param[in]	thread: The thread id
 * \return		The thread return value
 */
void	thread_join(pthread_t thread)
{
	if (!!pthread_join(thread, NULL))
		exit_error("pthread_join");
}
