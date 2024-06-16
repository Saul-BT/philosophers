/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblanco- <sblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:40:08 by sblanco-          #+#    #+#             */
/*   Updated: 2024/06/16 20:37:23 by sblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * \brief		Returns the current time in milliseconds
 * \return		The current time in milliseconds
 */
t_ms	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1e3 + tv.tv_usec / 1e3);
}

/**
 * \brief		Waits for a given number of milliseconds
 * \param[in]	ms	The number of milliseconds to wait
 */
void	wait(t_ms ms)
{
	t_ms	start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(500);
}
