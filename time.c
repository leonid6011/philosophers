#include "philo.h"

unsigned long long  get_time(void) //разобраться
{
	static struct timeval	time_now;

	gettimeofday(&time_now, NULL);
	return ((time_now.tv_sec * (unsigned long long)1000) + (time_now.tv_usec / 1000));
}