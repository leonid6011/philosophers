#include "philo.h"

int	ph_init(t_data_ph *data) //разобраться
{
	int	i;

	data->all_ph = (t_ph *)malloc(sizeof(*(data->all_ph)) * data->ph_nbr);
	if (!(data->all_ph))
		return (1);
	i = 0;
	while (i < data->ph_nbr)
	{
		data->all_ph[i].nbr_id = i;
		data->all_ph[i].count_eat = 0;
		data->all_ph[i].last_time_eat = 0;
		data->all_ph[i].data = data;
		data->all_ph[i].left_fork_m = &data->all_forks_m[i];
		if (i < data->ph_nbr - 1)
			data->all_ph[i].right_fork_m = &data->all_forks_m[i + 1];
		else
			data->all_ph[i].right_fork_m = &data->all_forks_m[0];
		i++;
	}
	return (0);
}

int	init_mutex(t_data_ph *data)
{
	int	i;

	data->all_forks_m = malloc(sizeof(pthread_mutex_t) * data->ph_nbr);
	if (data->all_forks_m == NULL)
		return (1);
	i = 0;
	while (i < data->ph_nbr)
	{
		if (pthread_mutex_init(&data->all_forks_m[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->food_record, NULL))
		return (1);
	if (pthread_mutex_init(&data->print, NULL))
		return (1);
	if (ph_init(data))
		return (1);
	return (0);
}

int	init_data(t_data_ph *data, int argc, char **argv)
{
	data->ph_nbr = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]) * 1000;
	data->time_to_sleep = ft_atoi(argv[4]) * 1000;
	data->is_dead = 1;
	if (argc == 6)
		data->eat_count_p = ft_atoi(argv[5]);
	else
		data->eat_count_p = -1;
	if (data->time_to_die < 60 || data->time_to_eat < 60 || data->time_to_sleep < 60)
	{
		printf("Error! Invalid parametrs\n");
		return (1);
	}
	if (data->ph_nbr < 1 || data->ph_nbr > 200)
	{
		printf("Error! Invalid parametrs\n");
		return (1);
	}
	if (init_mutex(data))
		return (1);
	return (0);
}