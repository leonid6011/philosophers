/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:45:50 by echrysta          #+#    #+#             */
/*   Updated: 2022/04/21 14:45:52 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_ph(t_data_ph *data, int nbr, char *str)
{
	unsigned long long	time;

	pthread_mutex_lock(&data->print);
	time = get_time() - data->start_prog;
	pthread_mutex_lock(&data->dead_or_nbr_m);
	if (data->dead_or_nbr)
		printf("%lld %d %s\n", time, nbr + 1, str);
	pthread_mutex_unlock(&data->dead_or_nbr_m);
	pthread_mutex_unlock(&data->print);
}
