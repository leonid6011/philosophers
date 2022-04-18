#include "philo.h"

void	print_ph(t_data_ph *data, int nbr, char *str, int flag)
{
    unsigned long long  time;

	pthread_mutex_lock(&data->print);
    time = get_time() - data->start_prog;
	if (data->is_dead)
		printf("%lld %d %s\n", time, nbr + 1, str);
	if (flag == 1)
		data->is_dead = 0;
	pthread_mutex_unlock(&data->print);
}