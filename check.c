#include "philo.h"

// void	how_much_eat(t_data_ph *data)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (i < data->ph_nbr)
// 	{
// 		if (data->all_ph->count_eat > data->eat_count_p)
// 			count++;
// 		i++;
// 	}
// 	if (count == data->ph_nbr)
// 		data->dead_or_nbr = 0;
// }

void	check(t_data_ph *data)
{
	int					i;
	unsigned long long	time;
	int					count;

	while (data->dead_or_nbr)
	{
		i = 0;
		while (i < data->ph_nbr && data->dead_or_nbr)
		{
			pthread_mutex_lock(&data->food_record);
			time = get_time() - data->start_prog - data->all_ph[i].last_time_eat;
			if (time > data->time_to_die)
			{
				print_ph(data, i, "died", 1);
				data->dead_or_nbr = 0;
			}
			pthread_mutex_unlock(&data->food_record);
			i++;
		}
		if (data->eat_count_p != -1 && data->dead_or_nbr)
			//how_much_eat(data);
		{
			i = 0;
			count = 0;
			while (i < data->ph_nbr)
			{
				if (data->all_ph->count_eat > data->eat_count_p)
					count++;
				i++;
			}
			if (count == data->ph_nbr)
				data->dead_or_nbr = 0;
		}
	}
}