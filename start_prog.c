#include "philo.h"

void	life_eat_ph(t_ph *one_ph)
{
	pthread_mutex_lock(one_ph->right_fork_m);
	print_ph(one_ph->data, one_ph->nbr_id, "has taken a fork", 0);
	pthread_mutex_lock(one_ph->left_fork_m);
	print_ph(one_ph->data, one_ph->nbr_id, "has taken a fork", 0);
	pthread_mutex_lock(&one_ph->data->food_record);
	print_ph(one_ph->data, one_ph->nbr_id, "is eating", 0);
	one_ph->last_time_eat = get_time() - one_ph->data->start_prog;
	pthread_mutex_unlock(&one_ph->data->food_record);
	my_usleep(one_ph->data->time_to_eat);
	one_ph->count_eat++;
	pthread_mutex_unlock(one_ph->right_fork_m);
	pthread_mutex_unlock(one_ph->left_fork_m);
}

void	life_sleep_and_think(t_ph *one_ph)
{
	print_ph(one_ph->data, one_ph->nbr_id, "is sleeping", 0);
	my_usleep(one_ph->data->time_to_sleep);
    print_ph(one_ph->data, one_ph->nbr_id, "is thinking", 0);
}

void	*life_prog(void *one_ph)
{
	t_ph		*one_phil;
	t_data_ph	*data;

	one_phil = (t_ph *) one_ph;
	data = one_phil->data;
	if (one_phil->nbr_id % 2)
		my_usleep(5);
	while (data->dead_or_nbr)
	{
		life_eat_ph(one_phil);
		life_sleep_and_think(one_ph);
		if (data->ph_nbr == 1)
			return (NULL);
	}
	return (NULL);
}

int	start_prog(t_data_ph *data)
{
	int		i;
	t_ph	*all_philos;

	i = 0;
	all_philos = data->all_ph;
	data->start_prog = get_time();
	while (i < data->ph_nbr)
	{
		if (pthread_create(&all_philos[i].philo_id_pthread, NULL, life_prog, &all_philos[i]))
			return (1);
		i++;
	}
	check(data);
	i = 0;
	while (i < data->ph_nbr)
	{
		if (!data->dead_or_nbr)
			pthread_detach(data->all_ph[i].philo_id_pthread);//почему (из лекции) 
		pthread_join(data->all_ph[i++].philo_id_pthread, NULL);
	}
	i = 0;
	while (i < data->ph_nbr)
		pthread_mutex_destroy(&data->all_forks_m[i++]);
	pthread_mutex_destroy(&data->food_record);
	pthread_mutex_destroy(&data->print);
	return (0);
}