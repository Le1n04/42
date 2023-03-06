#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s, const char *charset)
{

	while (*s)
	{
		int j = -1;
		while (charset[++j] != '\0')
			if (*s == charset[j])
				return ((char *) s);
		s++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char *s = "hola";
// 	char *charset = "la";
// 	char *a;
// 	char *b;

// 	ft_strpbrk(s, charset);
// 	strpbrk(s, charset);
// 	printf("%s\n%s\n", a, b);
// 	return 0;
// }

int main()
{
    // Declaring three strings
    char s1[] = "gksforgeeks";
    char s2[] = "app";
    char s3[] = "f";
    char* r, *t, *a, *b;
  
    r = strpbrk(s1, s2);
	a = ft_strpbrk(s1, s2); 
    if (r != 0)
        printf("%c\n%c\n", *r, *a);
    else
        printf("Character not found\n");
    t = strpbrk(s1, s3);
	b = ft_strpbrk(s1, s3);
    if (t != 0)
        printf("%c\n%c\n", *t, *b);
    else
        printf("Character not found\n");
  
    return (0);
}