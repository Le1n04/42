#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(char *src)
{
	int	i = 0;
	char *dst;

	while (src[i] != '\0')
		i++;
	dst = (char *)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (src[++i] != '\0')
		dst[i] = src[i];
	dst[i + 1] = '\0';
	return (dst);
}

int main()
{
    char source[] = "yeapapaaa 0 ";
    char* target = strdup(source);
	char* t = ft_strdup(source);
 
    printf("%s\n%s\n", target, t);
    return 0;
}
