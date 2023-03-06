#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	int i = -1;
	if (argc == 3)
	{
		while (argv[1][++i])
		{
			int j = -1;
			while (argv[2][++j])
			{
				int k = -1;
				if (argv[1][i] == argv[2][j])
				{
					int count = 0;
					int len = 0;
					while (argv[1][len] != '\0')
						len++;
					while (argv[1][i] != argv[1][++k] && argv[1][k] != '\0')
						count++;
					if (count != len)
						write (1, &argv[1][i], 1);
				}
			}
		}
	}
	write (1, "\n", 1);
	return (0);
}