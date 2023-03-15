#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;

	if (argc == 2)
	{
		int j = 0;
		while (argv[1][j])
			j++;
		while (argv[1][j] == ' ')
			j--;
		while (argv[1][i] == ' ')
			i++;
		while (argv[1][i] && i < j)
		{
			if (argv[1][i] == ' '  && i < j)
			{
				while (argv[1][i] == ' ' && argv[1][i + 1] == ' ')
					i++;
				if (i + 1 < j)
				{
					write (1, " ", 1);
					write (1, " ", 1);
					write (1, " ", 1);
				}
			}
			else
				write (1, &argv[1][i], 1);
			i++;
		}
	}
	return (write(1, "\n", 1), 0);
}