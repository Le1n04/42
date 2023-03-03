#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

int main()
{
	int	i;
	char *str = "Hola";

	i = ft_strlen(str);
	printf("%d\n", i);
	return (0);
}
