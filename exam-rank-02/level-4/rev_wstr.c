#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	put_str(char *str, int begin, int end)
{
	while (begin < end)
		write(1, &str[begin++], 1);
}

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	rev_wstr(char *str, int last)
{
	int i = -1;
	int j = -1;
	if(!last)
		return ;
	while (str[++i] && i <= last)
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			j = i;
	put_str(str, j + 1, i);
	if (j + 1)
	{
		if (last)
			write (1, " ", 1);
		rev_wstr(str, --j);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1], ft_strlen(argv[1]));
	return (write(1, "\n", 1), 0);
}