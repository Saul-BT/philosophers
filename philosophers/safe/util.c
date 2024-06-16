/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblanco- <sblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:50:30 by sblanco-          #+#    #+#             */
/*   Updated: 2024/06/16 13:24:00 by sblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safe.h"

/**
 * \brief		Print an error message to stderr
 * \param[in]	msg: The error message
 */
static void	print_error(char *msg)
{
	int	len;

	len = 0;
	while (msg && msg[len])
		len++;
	write(STDERR_FILENO, msg, len);
}

/**
 * \brief		Exit with an error message
 * \param[in]	msg: The error message
 */
void	exit_error(char *msg)
{
	print_error(msg);
	exit(EXIT_FAILURE);
}
