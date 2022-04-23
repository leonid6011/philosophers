/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:46:00 by echrysta          #+#    #+#             */
/*   Updated: 2022/04/21 14:46:01 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	life_eat_ph(t_ph *one_ph)
{
	pthread_mutex_lock(one_ph->right_fork_m);
	print_ph(one_ph->data, one_ph->nbr_id, "has taken a fork");
	pthread_mutex_lock(one_ph->left_fork_m);
	print_ph(one_ph->data, one_ph->nbr_id, "has taken a fork");
	pthread_mutex_lock(&one_ph->data->food_record);
	print_ph(one_ph->data, one_ph->nbr_id, "is eating");
	one_ph->last_time_eat = get_time() - one_ph->data->start_prog;
	pthread_mutex_unlock(&one_ph->data->food_record);
	my_usleep(one_ph->data->time_to_eat);
	pthread_mutex_lock(&one_ph->data->count_eat_m);
	one_ph->count_eat++;
	pthread_mutex_unlock(&one_ph->data->count_eat_m);
	pthread_mutex_unlock(one_ph->left_fork_m);
	pthread_mutex_unlock(one_ph->right_fork_m);
}

void	life_sleep_and_think(t_ph *one_ph)
{
	print_ph(one_ph->data, one_ph->nbr_id, "is sleeping");
	my_usleep(one_ph->data->time_to_sleep);
	print_ph(one_ph->data, one_ph->nbr_id, "is thinking");
}

void	*life_prog(void *one_ph)
{
	t_ph		*one_phil;
	t_data_ph	*data;

	one_phil = (t_ph *) one_ph;
	data = one_phil->data;
	if (one_phil->nbr_id % 2)
		my_usleep(5);
	pthread_mutex_lock(&data->dead_or_nbr_m);
	while (data->dead_or_nbr)
	{
		pthread_mutex_unlock(&data->dead_or_nbr_m);
		life_eat_ph(one_phil);
		life_sleep_and_think(one_ph);
		pthread_mutex_lock(&data->dead_or_nbr_m);
	}
	pthread_mutex_unlock(&data->dead_or_nbr_m);
	return (NULL);
}

int	strat_prog_first(t_data_ph *data)
{
	int		i;
	t_ph	*all_p;

	i = 0;
	all_p = data->all_ph;
	data->start_prog = get_time();
	while (i < data->ph_nbr)
	{
		if (pthread_create(&all_p[i].philo_id_pth, NULL, life_prog, &all_p[i]))
			return (1);
		i++;
	}
	return (0);
}

int	start_prog(t_data_ph *data)
{
	int		i;

	if (strat_prog_first(data))
		return (1);
	check(data);
	i = 0;
	if (data->ph_nbr == 1)
		pthread_detach(data->all_ph[0].philo_id_pth);
	else
	{
		while (i < data->ph_nbr)
			pthread_join(data->all_ph[i++].philo_id_pth, NULL);
	}
	m_destr_ph(data);
	return (0);
}
