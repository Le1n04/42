#include <unistd.h>
#include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	else
	{
		unsigned int n;
		if (a > b)
			n = a;
		else
			n = b;
		while (1)
		{
			if (n % a == 0 && n % b == 0)
				return (n);
			n++;
		}
}
}

int main(void)
{
	int a = -2;
	int b = 3;

	unsigned int n = lcm(a,b);
	printf("%d\n", n);
	return 0;
}