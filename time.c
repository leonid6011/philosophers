#include "philo.h"

unsigned long long  get_time(void)
{
	static struct timeval	time_now;

	gettimeofday(&time_now, NULL);
	return ((time_now.tv_sec * 1000) + (time_now.tv_usec / 1000));
}

void	my_usleep(unsigned long long time_argc)
{
	unsigned long long	time_now;

	time_now = get_time();
	while ((get_time() - time_now) < time_argc)
	{
		usleep(time_argc / 1000);
	}
}