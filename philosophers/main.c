/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblanco- <sblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 09:20:25 by sblanco-          #+#    #+#             */
/*   Updated: 2024/06/16 14:40:13 by sblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
	{
		exit_error("Error: the number of arguments is wrong\n\
 Usage: ./philo num_philos time_to_die time_to_eat time_to_sleep [num_eats]");
	}
	parse_input(argc - 1, argv + 1, &table);
	init_data(&table);
	return (0);
}
