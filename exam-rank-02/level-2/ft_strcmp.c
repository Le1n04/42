#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	result;
	int	rezult;

	i = -1;
	result = 0;
	rezult = 0;
	while (s1[++i] != '\0')
		result = result + s1[i];
	i = -1;
	while (s2[++i] != '\0')
		rezult = rezult + s2[i];
	return (result - rezult);
}

int	main(void)
{
	char *s1 = "hola";
	char *s2 = "hoLa";

	int n = ft_strcmp(s1,s2);
	int j = strcmp(s1,s2);
	printf("%d\n%d\n", n, j);
	return (0);
}