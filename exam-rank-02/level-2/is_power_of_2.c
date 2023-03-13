#include <unistd.h>
#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	while (n > 1)
	{
		n /= 2;
		if (n % 2 != 0 && n != 1)
			return (0);
	}
	return (1);
}

int main(void)
{
	int n = 15;
	int x = is_power_of_2(n);

	printf("%d\n", x);
	return (0);
}
