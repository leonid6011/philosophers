#include "philo.h"

void	how_much_eat(t_data_ph *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < data->ph_nbr)
	{
		if (data->all_ph->count_eat > data->eat_count_p)
			count++;
		i++;
	}
	if (count == data->ph_nbr)
		data->is_dead = 0;
}

void	check(t_data_ph *data)
{
	int					i;
	unsigned long long	time;

	while (data->is_dead)
	{
		i = 0;
		while (i < data->ph_nbr && data->is_dead)
		{
			pthread_mutex_lock(&data->food_record);
			time = get_time() - data->start_prog - data->all_ph[i].last_time_eat;
			if (time > data->time_to_die)
			{
				print_ph(data, i, "died", 1);
				printf("golod\n");
				data->is_dead = 0;
			}
			pthread_mutex_unlock(&data->food_record);
			usleep(150);
			i++;
		}
		if (data->eat_count_p != -1 && data->is_dead)
			how_much_eat(data);
	}
}