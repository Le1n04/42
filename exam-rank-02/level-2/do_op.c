#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i;
	int	tmp;
	int	n;
	int	m;

	i = -1;
	if (argc == 4)
	{
		n = atoi(argv[1]);
		m = atoi(argv[3]);
		if (argv[2][0] == '+')
			tmp = n + m;
		else if (argv[2][0] == '-')
			tmp = n - m;
		else if (argv[2][0] == '*')
			tmp = n * m;
		else if (argv[2][0] == '/')
			tmp = n / m;
		else if (argv[2][0] == '%')
			tmp = n % m;
		printf("%d\n", tmp);
	}
	return (0);
}