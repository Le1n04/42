#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int n = start;
	int len = 0;
	while (n <= end)
	{
		len++;
		n++;
	}
	int *array = malloc(sizeof(int) * len);
	int i = -1;
	while (++i < len)
		array[i] = start++;
	return (array);
}

int main(void)
{
	int *array;

	array = ft_range(1, 9);
	int i = -1;
	while (array[++i] != '\0')
		printf("%d\n", array[i]);
	return 0;
}