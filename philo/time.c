/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:46:08 by echrysta          #+#    #+#             */
/*   Updated: 2022/04/21 14:46:10 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	get_time(void)
{
	static struct timeval	time_now;
	unsigned long long		time;

	gettimeofday(&time_now, NULL);
	time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
	return (time);
}

void	my_usleep(unsigned long long time_argc)
{
	unsigned long long	time_now;

	time_now = get_time();
	while ((get_time() - time_now) < time_argc)
	{
		usleep(time_argc);
	}
}
