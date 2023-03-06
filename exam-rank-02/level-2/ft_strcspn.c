#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i = -1;
	size_t	count = 0;

	while (s[++i] != '\0')	
	{
		int	j = -1;
		while (reject[++j] != '\0')
			if (s[i] == reject[j])
				return (count);
		count++;
	}
	return (count);
}

int main(void)
{
	char *s = "hola";
	size_t n;
	size_t m;
	char *reject = "c";

	n = ft_strcspn(s, reject);
	m = strcspn(s, reject);
	printf("%zu\n%zu\n", n, m);
	return (0);
}