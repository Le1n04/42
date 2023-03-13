#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i = -1;
	int j = -1;
	
	if (argc == 2)
	{
		while (argv[1][++i])
		{
			if (argv[1][i] != '_')
				write (1, &argv[1][i], 1);
			else if (argv[1][i] == '_')
			{
				argv[1][++i] = argv[1][i] - 32;
				write (1, &argv[1][i], 1);
			}
		}
	}
	return 0;
}