#include <unistd.h>
#include <stdio.h>

int ft_strchr(char *str, char c)
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
	int j = -1;
	int len = 0;
	int count = 0;
	int tmp;

	if (argc == 3)
	{
		while (argv[1][len])
			len++;
		while (argv[1][++i])
		{
			tmp = count;
			while (argv[2][++j])
			{
				if (argv[2][j] == argv[1][i])
				{
					count++;
				}
				if (count != tmp)
					break ;
			}
		}
		int i = -1;
		if (count == len)
			while (argv[1][++i])
				write (1, &argv[1][i], 1);
	}
	return (write(1, "\n", 1), 0);
}