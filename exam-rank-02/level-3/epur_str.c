#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;

	if (argc == 2)
	{
		while (argv[1][j])
			j++;
		while (argv[1][i] == ' ' && i < j)
			i++;
		while (argv[1][i] && i < j)
		{
			if (argv[1][i] == ' ')
			{
				while (argv[1][i] == ' ')
					i++;
				if (argv[1][i])
					write (1, " ", 1);
			}
			if (argv[1][i] != ' ' && i < j)
				write (1, &argv[1][i], 1);
			i++;
		}
	}
	return (write(1, "\n", 1), 0);
}