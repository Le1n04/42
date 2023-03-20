#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int tmp = nbr;
	int len = 0;
	int sign = 0;

	if (nbr == 0)
		return ("0");
	if (tmp < 0)
	{
		len++;
		sign = -1;
		nbr = nbr * -1;
	}
	while (tmp)
	{
		tmp = tmp / 10;
		len++;
	}
	char *str = malloc(sizeof(char) * len);
	if (sign == -1)
		str[0] = '-';
	str[len] = '\0';
	while (nbr > 0)
	{
		str[--len] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (str);
}

int main(void)
{
	int n = -1;
	char *len = ft_itoa(n);
	printf("%s\n", len);
	return 0;
}