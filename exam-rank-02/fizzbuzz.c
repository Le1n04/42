#include <unistd.h>

void	print_number(int i)
{
	char	str[10] = "0123456789";

	if (i > 9)
		print_number(i / 10);
	write (1, &str[i % 10], 1);
}

int main(void)
{
	int	i = 0;
	while (++i <= 100)
	{
		if (i % 15 == 0)
			write (1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write (1, "fizz", 4);
		else if (i % 5 == 0)
			write (1, "buzz", 4);
		else
			print_number(i);
		write (1, "\n", 1);
	}
	return (0);
}