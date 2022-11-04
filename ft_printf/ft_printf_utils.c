/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:12:30 by djanssen          #+#    #+#             */
/*   Updated: 2022/11/04 12:05:02 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa(n);
	i = ft_printstr(str);
	return (free(str), i);
}

int	ft_printunsigned(unsigned int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa(n);
	if (str == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else
	{
		if (str[i] == '-')
			i++;
		while (str[i])
		{
			write(1, str[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_printpercentage(void)
{
	write (1, "%", 1);
	return (1);
}
