/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:45:04 by echrysta          #+#    #+#             */
/*   Updated: 2022/04/21 14:45:07 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	how_much_eat(t_data_ph *data)
{
	int	i;
	int	counter_eat;

	i = 0;
	counter_eat = 0;
	while (i < data->ph_nbr)
	{
		pthread_mutex_lock(&data->count_eat_m);
		if (data->all_ph->count_eat > data->eat_count_p)
			counter_eat++;
		pthread_mutex_unlock(&data->count_eat_m);
		if (counter_eat == data->ph_nbr)
		{
			pthread_mutex_lock(&data->dead_or_nbr_m);
			data->dead_or_nbr = 0;
			pthread_mutex_unlock(&data->dead_or_nbr_m);
		}
		i++;
	}
}

void	check_help(t_data_ph *data, int i)
{
	unsigned long long	time;
	unsigned long long	t;

	pthread_mutex_lock(&data->food_record);
	t = get_time() - data->start_prog;
	time = t - data->all_ph[i].last_time_eat;
	if (time > data->time_to_die)
	{
		print_ph(data, i, "died");
		pthread_mutex_lock(&data->dead_or_nbr_m);
		data->dead_or_nbr = 0;
		pthread_mutex_unlock(&data->dead_or_nbr_m);
	}
	pthread_mutex_unlock(&data->food_record);
}

void	check(t_data_ph *data)
{
	int					i;

	pthread_mutex_lock(&data->dead_or_nbr_m);
	while (data->dead_or_nbr)
	{
		pthread_mutex_unlock(&data->dead_or_nbr_m);
		i = 0;
		while (i < data->ph_nbr)
		{
			check_help(data, i);
			i++;
		}
		if (data->eat_count_p != -1)
			how_much_eat(data);
		pthread_mutex_lock(&data->dead_or_nbr_m);
	}
	pthread_mutex_unlock(&data->dead_or_nbr_m);
}
