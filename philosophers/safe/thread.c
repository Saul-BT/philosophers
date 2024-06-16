/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblanco- <sblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:16:12 by sblanco-          #+#    #+#             */
/*   Updated: 2024/06/16 13:23:22 by sblanco-         ###   ########.fr       */
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
	int			ret;
	pthread_t	thread;

	ret = pthread_create(&thread, NULL, routine, arg);
	if (!!ret)
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
	int	ret;

	ret = pthread_join(thread, NULL);
	if (!!ret)
		exit_error("pthread_join");
}
