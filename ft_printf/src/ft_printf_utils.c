/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:12:30 by djanssen          #+#    #+#             */
/*   Updated: 2022/11/08 14:01:28 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Function to print a string when '%s' is used.
 * 
 * @param str string to be printed.
 * @return (len) length of 's'.
 */
int	ft_printstr(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[len])
	{
		write (1, &str[len], 1);
		len++;
	}
	return (len);
}

/**
 * @brief Function to print a number converted from 'int c'
 * to a char *str when '%d' is called.
 * 
 * @param n number to be converted and printed.
 * @return length of 'n' (len param).
 */
int	ft_printnbr(int n)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa(n);
	len = ft_printstr(str);
	return (free(str), len);
}

/**
 * @brief Function to print an unsigned decimal number 
 * from 'int n' to 'char *str'
 * @param n number to be converted and printed.
 * @return len - length of the string printed.
 */
int	ft_printunsigned(unsigned int n)
{
	int		len;
	char	*str;

	len = -1;
	str = ft_itoax(n);
	if (str != 0)
	{
		if (str[0] == '-')
			len++;
		while (str[++len])
			write(1, &str[len], 1);
	}
	else
	{
		write (1, "0", 1);
		return (1);
	}
	return (len);
}

/**
 * @brief Function to print a '%' symbol when '%%' is called.
 * 
 * @return value 1 as the function only prints a percentage symbol.
 */
int	ft_printpercentage(void)
{
	write (1, "%", 1);
	return (1);
}
