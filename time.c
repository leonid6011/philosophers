#include "philo.h"

unsigned long long  get_time(void) //разобраться
{
	static struct timeval	time_now;
    unsigned long long      time;

	gettimeofday(&time_now, NULL);
    time = (time_now.tv_sec * (unsigned long long)1000) + (time_now.tv_usec / 1000);
	return (time);
}