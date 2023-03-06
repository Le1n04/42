#include <unistd.h>

void	ft_putchar_n(char c, int i)
{
	while (i > 0)
	{
		write (1, &c, 1);
		i--;
	}
}

int	repeat_alpha(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 'a' || *str <= 'z')
			ft_putchar_n(*str, *str + 1 - 'a');
		else if (*str >= 'A' || *str <= 'Z')
			ft_putchar_n(*str, *str +, - 'A');
		else
			write (1, str, 1);
		++str;
	}
}
