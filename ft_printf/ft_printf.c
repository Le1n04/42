/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:12:30 by djanssen          #+#    #+#             */
/*   Updated: 2022/11/04 11:36:39 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_format(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		length += ft_printstr(va_arg(args, char *));
	// else if (format == 'p')
	// 	length += ft_printpointer(va_arg(args, int));
	else if (format == 'd' || format == 'i')
		length += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		length += ft_printunsigned(va_arg(args, int));
	// else if (format == 'x' || format == 'X')
	// 	length += ft_printhex(va_arg(args, int), format);
	else if (format == '%')
		length += ft_printpercentage();
	return (length);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		length;
	va_list	args;

	va_start(args, format);
	i = -1;
	length = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			length += ft_format(args, format[i + 1]);
		else
			length += ft_printchar(format[i]);
	}
	va_end(args);
	return (length);
}
