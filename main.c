#include "philo.h"

int main(int argc, char *argv[])
{
	t_data_ph	data;

	if (argc < 5 || argc > 6)
	{
		printf("Error! Invalid number argv\n");
		return (1);
	}
	if (check_input(argv))
	{
		printf("Error! Invalid argv\n");
		return (1);
	}
	if (init_data(&data, argc, argv))
	{
		printf("In init_data!\n");
		return (1);
	}
	if (start_prog(&data))
	{
		printf("In start_prog!\n");
		return (1);
	}
	free(data.all_forks_m);
	free(data.all_ph);
	return (0);
}