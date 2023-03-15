#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = -1;
		int j = 0;
		int len = 0;
		int count = 0;
		while (argv[1][len])
			len++;
		while (argv[1][++i])
		{
			while(argv[2][j] != argv[1][i] && argv[2][j])
				j++;
			if (argv[2][j] == argv[1][i])
				count++;
		}
		if (count == len)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	return (write(1, "\n", 1), 0);
}