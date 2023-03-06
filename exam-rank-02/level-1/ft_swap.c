#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int	i = 1;
	int	a = 3;

	ft_swap(&a, &i);
	printf("%d %d\n", i, a);
	return (0);
}
