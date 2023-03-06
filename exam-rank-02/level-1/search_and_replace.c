#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;

	i = -1;
	if (argc == 4 && argv[2][1] == '\0' && argv[3][1] == '\0')
	{
		if ((argv[2][0] >= 'a' && argv[2][0] <= 'z') || (argv[2][0] >= 'A' && argv[2][0] <= 'Z'))
		{
			if ((argv[3][0] >= 'a' && argv[3][0] <= 'z') || (argv[3][0] >= 'A' && argv[3][0] <= 'Z'))
			{
				while (argv[1][++i] != '\0')
				{
					if (argv[1][i] == argv[2][0])
						argv[1][i] = argv[3][0];
					write (1, &argv[1][i], 1);
				}
			}
		}
	}
	write(1, "\n", 1);
}
