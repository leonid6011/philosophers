#include "philo.h"

void	print_ph(t_data_ph *data, int nbr, char *str, int flag)
{
    unsigned long long  time;

	pthread_mutex_lock(&data->print);
    time = get_time() - data->start_prog;
	if (data->dead_or_nbr)
		printf("%lld %d %s\n", time, nbr + 1, str);
	if (flag == 1)
		data->dead_or_nbr = 0;
	pthread_mutex_unlock(&data->print);
}