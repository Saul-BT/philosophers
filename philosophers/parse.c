/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblanco- <sblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:32:18 by sblanco-          #+#    #+#             */
/*   Updated: 2024/06/16 17:37:50 by sblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static inline bool	is_digit(const char c)
{
	return (c >= '0' && c <= '9');
}

static inline bool	is_space(const char c)
{
	return ((c >= '\t' && c <= '\r') || (c == ' '));
}

/**
 * \brief		Get a valid number string from a char pointer
 * \param[in]	str: The string to get the number from
 * \return		The valid number string
 */
static const char	*get_valid_num_str(const char *str)
{
	int	len;

	len = 0;
	while (is_space(*str))
		str++;
	if (*str == '-')
		exit_error("Error: negative args not allowed");
	if (*str == '+')
		str++;
	while (is_digit(str[len]))
		len++;
	if (!is_digit(*str))
		exit_error("Error: non-numeric/alpha-numeric args not allowed");
	if (len > 10)
		exit_error("Error: numbers greater than INT_MAX not allowed");
	return (str);
}

/**
 * \brief		Converts a string into a int
 * \param[in]	str: The string to convert
 * \return		Int representation of the string
 */
static int	ft_atoi(const char *str)
{
	long		result;
	const char	*numeric;

	result = 0;
	numeric = get_valid_num_str(str);
	while (is_digit(*numeric))
	{
		if (result > INT_MAX)
			exit_error("Error: numbers greater than INT_MAX not allowed");
		result = result * 10 + *(numeric++) - '0';
	}
	return ((int)result);
}

/**
 * \brief		Parse the arguments and use the data to fill the table
 * \param[in]	argc: The argument count
 * \param[in]	args: Represent the following information:
 *  num_philos time_to_die time_to_eat time_to_sleep [num_max_eats]
 * \param[in]	table: Pointer to the empty table struct
 */
void	parse_input(int argc, char **args, t_table *table)
{
	table->max_eat_count = -1;
	table->philo_count = ft_atoi(args[0]);
	table->time_to_die = ft_atoi(args[1]);
	table->time_to_eat = ft_atoi(args[2]);
	table->time_to_sleep = ft_atoi(args[3]);
	if (argc == 5)
		table->max_eat_count = ft_atoi(args[4]);
}
