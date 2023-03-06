#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[1][++i])
	{
		j = 0;
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
		{
			while ('a' + j != argv[1][i])
				j++;
			argv[1][i] = 'z' - j; 
		}
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			while ('A' + j != argv[1][i])
				j++;
			argv[1][i] = 'Z' - j; 
		}
		write (1, &argv[1][i], 1);
	}
	write (1, "\n", 1);
	return (0);
}