#include <limits.h>

int valid_number_control(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i])
		return (1);
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
int doubles_control(long long *args, int count)
{
	int i = 0;
	int j;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (args[i] == args[j])
				return 1;
			j++;
		}
		i++;
	}
	return 0;
}

int integer_limits_control(long long nmbr)
{
	if (nmbr > INT_MAX || nmbr < INT_MIN)
		return (1);
	return (0);
}