/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblanco- <sblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:30:58 by sblanco-          #+#    #+#             */
/*   Updated: 2024/06/16 19:43:10 by sblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safe.h"

/**
 * \brief		Create a mutex safely
 * \return		Pointer to the wrapped mutex
 */
void	*mutex_create(void)
{
	t_mutex	*m;

	m = secure_malloc(sizeof(t_mutex));
	if (!!pthread_mutex_init(&m->mutex, NULL))
	{
		free(m);
		exit_error("pthread_mutex_init");
	}
	m->is_created = true;
	return ((void *)m);
}

/**
 * \brief		Destroy a mutex safely
 * \param[in]	m: Pointer to the wrapped mutex
 */
void	mutex_destroy(t_mutex *m)
{
	int	ret;

	ret = 0;
	if (!m)
		return ;
	if (m->is_created)
		ret = pthread_mutex_destroy(&m->mutex);
	free(m);
	if (!!ret)
		exit_error("pthread_mutex_destroy");
}

/**
 * \brief		Lock a mutex safely
 * \param[in]	m: Pointer to the wrapped mutex
 */
void	mutex_lock(t_mutex *m)
{
	int	ret;

	ret = 0;
	if (!m)
		return ;
	if (m->is_created)
		ret = pthread_mutex_lock(&m->mutex);
	if (!!ret)
		exit_error("pthread_mutex_lock");
}

/**
 * \brief		Unlock a mutex safely
 * \param[in]	m: Pointer to the wrapped mutex
 */
void	mutex_unlock(t_mutex *m)
{
	int	ret;

	ret = 0;
	if (!m)
		return ;
	if (m->is_created)
		ret = pthread_mutex_unlock(&m->mutex);
	if (!!ret)
		exit_error("pthread_mutex_unlock");
}
