#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i = -1;
	int	j = 0;
	int k;
	if (argc == 2)
	{
		while (argv[1][++i])
			;
		while (argv[1][i - 1] == ' ' && i >= 0)
			i--;
		k = i;
		while (argv[1][i - 1] != ' ' && i >= 0)
			i--;
		while (i <= k)
			write (1, &argv[1][i++], 1);
	}
	write (1, "\n", 1);
	return (0);
}