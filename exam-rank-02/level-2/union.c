#include <unistd.h>
#include <stdio.h>

int ft_strnchr(char *str, char c, int n)
{
	int i = -1;

	while (++i < n && str[i])
		if (str[i] == c)
			return (1);
	return (0);
}

int ft_strchr(char *str, char c)
{
	int i = -1;

	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int i = -1;
	
	if (argc == 3)
	{
		while (argv[1][++i])
		{
			if (!ft_strnchr(argv[1], argv[1][i], i))
				write (1, &argv[1][i], 1);
		}
		i = -1;
		while (argv[2][++i])
		{
			if (!ft_strnchr(argv[2], argv[2][i], i) && !ft_strchr(argv[1], argv[2][i]))
				write (1, &argv[2][i], 1);
		}
	}
	return (write(1, "\n", 1), 0);
}