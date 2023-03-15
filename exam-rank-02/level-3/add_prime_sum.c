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

int	is_prime(int num)
{
	int i = 3;
	
	if (num <= 1)
		return (0);
	if (num % 2 == 0 && num > 2)
		return (0);
	while (i < (num / 2))
	{
		if (num % i == 0)
			return 0;
		i += 2;
	}
	return 1;
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	put_nbr(int n)
{
	int nbr;

	if (n < 0)
	{
		ft_putchar('-');
		nbr = n * -1;
	}
	else
		nbr = n;
	if (nbr >= 10)
		put_nbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}

int main(int argc, char **argv)
{
	int sum = 0;

	if (argc == 2)
	{
		int n = ft_atoi(argv[1]);
		while (n > 0)
		{
			if (is_prime(n--))
			{
				sum += (n + 1);
			}
		}
	}
	put_nbr(sum);
	write (1, "\n", 1);
	return (0);
}