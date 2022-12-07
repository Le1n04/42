/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:14:00 by djanssen          #+#    #+#             */
/*   Updated: 2022/11/17 12:33:45 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_gethexa(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_gethexa(n / 16, format);
		ft_gethexa(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else if (format == 'x')
			ft_putchar_fd((n + 'a' - 10), 1);
		else if (format == 'X')
			ft_putchar_fd((n + 'A' - 10), 1);
	}
}

int	ft_hexalen(unsigned int n)
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

int	ft_printhexa(unsigned int n, const char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	ft_gethexa(n, format);
	return (ft_hexalen(n));
}
