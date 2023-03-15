#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int nbr = start;
	int i = 0;
	while (nbr <= end)
	{
		i++;
		nbr++;
	}
	int *n = malloc(sizeof(int) * i);
	i = 0;
	while (end >= start)
	{
		n[i] = end;
		end--;
		i++;
	}
	return (n);
}

int main(void)
{
	int *array;

	array = ft_rrange(0, 0);
	int i = -1;
	printf("a%d\na", array[0]);
	return 0;
}