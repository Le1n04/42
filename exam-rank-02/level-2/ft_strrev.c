#include <stdio.h>
#include <string.h>

char	*ft_strrev(char *str)
{
	int	i = 0;
	char *dst;
	while (str[i] != '\0')
		i++;
	int j = i;
	i = -1;
	int tmp = j;
	while (i < tmp)
		dst[++i] = str[--j];
	dst[i] = '\0';
	return (dst);
}

int main(void)
{
	char *a = " 0 3 ";
	char *b = ft_strrev(a);
	printf("orig:%s\nres:%s\n", a, b);
	return (0);
}