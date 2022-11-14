/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:14:00 by djanssen          #+#    #+#             */
/*   Updated: 2022/11/14 19:34:14 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Get length of 'n'
 * 
 * @param uintptr_t unsigned integer type that is
 *  capable of storing a data pointer.
 * @return Length of 'n' (len).
 */
int	ft_pointerlen(uintptr_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

/**
 * @brief If n >= 16 it will enter until the number is <= 9 and 
 * print the number or 9>n<=16 and it'll print the letter.
 * 
 * @param n number given
 */
void	ft_getpointer(uintptr_t n)
{
	if (n >= 16)
	{
		ft_getpointer(n / 16);
		ft_getpointer(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
}

int	ft_printpointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		ft_getpointer(ptr);
		len += ft_pointerlen(ptr);
	}
	return (len);
}
