#include <unistd.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = -1;
	sign = 1;
	res = 0;
	while (str[++i])
	{
		if (str[0] == '-')
			sign = -1;
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
	}
	return (sign * res);
}

int main(void)
{
	char *str = "+123";
	int	n;

	n = ft_atoi(str);
	printf("%d\n", n);
	return (0);
}