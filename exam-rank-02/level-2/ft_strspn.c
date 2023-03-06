#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int 	i = -1;
	size_t	count = 0;
	size_t check = 0;

	while (s[++i] != '\0')
	{
		int j = -1;
		check = count;
		while (accept[++j] != '\0')
		{
			if (accept[j] == s[i])
				count++;
		}
		if (check == count)
			return (count);
	}
	return (count);
}

int main(void)
{
	char *s = "1234567890";
	char *accept = "123457890";
	size_t a = ft_strspn(s, accept);
	size_t b = strspn(s, accept);
	printf("%zu\n%zu\n", a, b);
	return 0;
}