#include <unistd.h>
#include <stdio.h>

int	max(int* tab, unsigned int len)
{
	int n = 0;
	if (len > 0)
	{
	n = tab[len - 1];
	while (--len > 0)
		if (tab[len] > n)
			n = tab[len];
	}
	return (n);
}

int main(void)
{
	int tab[] = {2,123,78};
	unsigned int len = 3;
	int n = max(tab, len);
	printf("%d\n", n);
	return 0;
}