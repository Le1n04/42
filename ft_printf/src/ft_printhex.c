/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:12:30 by djanssen          #+#    #+#             */
/*   Updated: 2022/11/10 12:47:16 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Get len of 'n' to return it right after.
 * 
 * @param n number given.
 * @return len of 'n'.
 */
int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

/**
 * @brief This function passes 'int n' from decimal to hexadecimal. 
 * @param n number given.
 * @param format param to know if we are on uppercase or lowercase X.
 */
void	ft_get_hex(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_get_hex(n / 16, format);
		ft_get_hex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else if (format == 'x')
			ft_putchar_fd((n - 10 + 'a'), 1);
		else if (format == 'X')
			ft_putchar_fd((n - 10 + 'A'), 1);
	}
}

/**
 * @brief This is the main function. 
 * It will use the ft_get_hex function if n != 0, if 0 it will print a 0.
 * @param n number given.
 * @param format 'X' or 'x'.
 * @return length according to ft_hexlen.
 */
int	ft_printhex(unsigned int n, const char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_get_hex(n, format);
	return (ft_hexlen(n));
}
