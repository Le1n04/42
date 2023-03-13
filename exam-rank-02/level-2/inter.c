#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_strchr(char c, char *str)
{
	int i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int i = -1;
	int	j = -1;
	if (argc == 3)
	{
		while (argv[1][++i])
		{
			if (ft_strchr(argv[1][i], argv[2]))
			{
				j = i;
				int count = 0;
				while (--j >= 0)
					if (argv[1][i] == argv[1][j])
						count = 1;
				if (count == 0)
					write (1, &argv[1][i], 1);
			}
		}
	}
	write (1, "\n", 1);
	return (0);
}