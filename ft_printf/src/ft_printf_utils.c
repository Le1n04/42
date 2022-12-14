/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:50:00 by djanssen          #+#    #+#             */
/*   Updated: 2022/11/14 17:31:25 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printpercentage(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int		i;

	i = 0;
	if (!str)
	{	
		write (1, "(null)", 6);
		return (6);
	}
	else
		while (str[i])
			write(1, &str[i++], 1);
	return (i);
}

int	ft_printnbr(int n)
{
	int		i;
	char	*nstr;

	nstr = ft_itoa(n);
	i = ft_printstr(nstr);
	free(nstr);
	return (i);
}

int	ft_printunsignednbr(unsigned int n)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else
	{
		str = ft_unsigneditoa(n);
		i += ft_printstr(str);
		free (str);
	}
	return (i);
}
