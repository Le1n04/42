#include <stdlib.h>
#include <stdio.h>

int is_prime(int n)
{
	int i = 1;

	while (++i <= n / 2)
	{
		if (n % i == 0)
			return (0);
		if (i == n / 2)
			return (1);
	}
	return (1);
}

int main(int argc, char **argv)
{
	int i = 1;

	if (argc == 2)
	{
		int n = atoi(argv[1]);
		int tmp = n;
		if (n == 1)
			printf("1");
		while (++i <= n)
		{
			if (tmp % i == 0)
			{
				printf("%d", i);
				tmp = tmp / i;
				i = 1;
				if (tmp != 1)
					printf("*");
			}
		}
	}
	printf("\n");
	return 0;
}