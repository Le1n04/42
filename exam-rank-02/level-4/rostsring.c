#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int i = 0;
		int flen = 0;
		if (argv[1][0] == ' ' || argv[1][0] == '\t' || argv[1][0] == '\n')
			while (argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == '\n')
				i++;
		int tmp = i;
		while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i])
		{
			i++;
			flen++;
		}
		if (ft_strlen(argv[1]) != i)
		{
			char *str = malloc(sizeof(char) * flen);
			int j = 0;
			int count = 0;
			while (j < flen)
			{
				str[j] = argv[1][tmp];
				j++;
				tmp++;
			}
			while (argv[1][++i])
			{
				if ((argv[1][i] == ' ' && argv[1][i - 1] != ' ') || argv[1][i] != ' ')
				{
					write (1, &argv[1][i], 1);
					count++;
				}
			}
			int k = -1;
			if (count > 0)
				write (1, " ", 1);
			while (str[++k])
				write (1, &str[k], 1);
		}
		else
			while(argv[1][tmp])
				write (1, &argv[1][tmp++], 1);
	}
	return (write(1, "\n", 1), 0);
}