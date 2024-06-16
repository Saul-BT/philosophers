/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblanco- <sblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:16:05 by sblanco-          #+#    #+#             */
/*   Updated: 2024/06/16 13:20:23 by sblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safe.h"

/**
 * \brief		Allocates memory for a pointer
 * \param[in]	size: The size of the memory to allocate
 * \return		Pointer to the allocated memory
 */
void	*secure_malloc(size_t size)
{
	void	*allocated;

	allocated = malloc(size);
	if (allocated == NULL)
		exit_error("Error: failed to allocate memory");
	return (allocated);
}
