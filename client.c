#include "minitalk.h"

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;
	int	j;

	i = 0;
	pid = ft_atoi(av[1]);
	if (ac != 3)
		return (0);
	while (av[2][i])
	{
		j = 7;
		while (j >= 0)
		{
			if ((av[2][i] >> j) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			j--;
			usleep(10000);
		}
		i++;
	}
}