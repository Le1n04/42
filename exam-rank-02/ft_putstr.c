#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i = -1;

	while (str[++i])
		write (1, &str[i], 1);
}

int main(void)
{
	char *str = "hola que tal";

	ft_putstr(str);
}
