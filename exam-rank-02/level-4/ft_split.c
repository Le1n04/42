#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	**ft_split(char *str)
{
	int	words = 0;
	int i = 0;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		if (i == 0 && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			words++;
		if (i > 0 && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') && (str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == '\n'))
			words++;
		i++;
	}
	char **export = (char **)malloc(sizeof(char *) * (words));
	i = 0;
	int wc = 0;
	while (str[i])
	{
		int j = 0;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			i++;
			j++;
		}
		export[wc] = (char *)malloc(sizeof(char) * (j));
		wc++;
		i++;
	}
	i = 0;
	wc = 0;
	while (str[i])
	{
		int j = 0;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			export[wc][j++] = str[i++];
		export[wc][j] = '\0';
		wc++;
		i++;
	}
	return (export);
}

int main(void)
{
	char **str = ft_split("HOLA QUE TAL");

	int i = -1;
	while (str[++i] != NULL)
	{
		printf("String: %s ", str[i]);
		write(1, "TEST\n", 5);
	}
}