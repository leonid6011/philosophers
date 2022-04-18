#include "philo.h"

int	check_input(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	t_data_ph	data;

	if (argc < 5 || argc > 6)
	{
		printf("Error! Invalid argv\n");
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