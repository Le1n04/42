#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int		i;

	i = -1;
	while (s2[++i] != '\0')
	{
		s1[i] = s2[i];
	}
	s1[i] = '\0';
	return (s1);
}

int	main(void)
{
	char dst[] = "123456789";
	char src[] = "inicio";
	printf("%s\n", ft_strcpy(dst, src));
	printf("%s\n", strcpy(dst, src));
	return (0);
}
