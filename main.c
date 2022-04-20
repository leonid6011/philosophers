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
		printf("Error in init_mutex!\n");
		return (1);
	}
	if (start_prog(&data))
	{
		printf("Error in start_prog!\n");
		return (1);
	}
	return (0);
}