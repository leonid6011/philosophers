#include "philo.h"

int	ft_atoi(const char *str)
{
	long	result;
	long	minus;
	int		i;

	minus = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			minus = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i++] - '0';
		if (result > 2147483647 && minus == 1)
			return (-1);
		if (result > 2147483648 && minus == -1)
			return (0);
	}
	result = result * minus;
	return ((int)result);
}

