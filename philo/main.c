/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:45:32 by echrysta          #+#    #+#             */
/*   Updated: 2022/04/21 14:45:34 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_data_ph(t_data_ph	data)
{
	free(data.all_forks_m);
	free(data.all_ph);
}

int	main_helper(t_data_ph	data)
{
	if (init_mutex(&data))
	{
		clear_data_ph(data);
		return (1);
	}
	ph_init(&data);
	if (start_prog(&data))
	{
		clear_data_ph(data);
		printf("In start_prog!\n");
		return (1);
	}
	clear_data_ph(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data_ph	data;

	if (argc < 5 || argc > 6)
	{
		printf("Error! Invalid number argv\n");
		return (1);
	}
	if (check_input(argv))
	{
		printf("Error! Invalid argv\n");
		return (1);
	}
	if (init_data(&data, argc, argv))
	{
		free(data.all_ph);
		printf("In init_data!\n");
		return (1);
	}
	if (main_helper(data))
		return (1);
	return (0);
}
