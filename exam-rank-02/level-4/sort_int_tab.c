#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	check_if_ordered(int *tab, unsigned int size)
{
	unsigned int i = -1;
	while (++i < size - 1)
		if (tab[i] > tab[i + 1])
			return (0);
	return (1);
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	int tmp;
	while (!check_if_ordered(tab, size))
	{
		i = -1;
		while (++i < size - 1)
		{
			if (tab[i] > tab[i + 1] && i < size)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
		}
	}
}

int main(void)
{
	int tab[] = {1,3,3,4,10,3,51,0,42};
	int i = -1;

	while (++i < 9)
		printf("%d\n", tab[i]);
	i = -1;
	sort_int_tab(tab, 9);
	while (++i < 9)
		printf("%d\n", tab[i]);
	return 0;
}