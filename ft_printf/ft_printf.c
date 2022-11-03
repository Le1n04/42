/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:12:30 by djanssen          #+#    #+#             */
/*   Updated: 2022/11/03 16:47:35 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_printpercentage(void)
{
	write (1, '%', 1);
	return (1);
}

int	ft_format(va_list *args, const char *format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_printchar(args);
	if (format == 's')
		length += ft_printstr(args);
	if (format == 'p')
		length += ft_printpointer(args);
	if (format == 'd' || format == 'i')
		length += ft_printnbr(args);
	if (format == 'u')
		length += ft_printunsigned(args);
	if (format == 'x' || format == 'X')
		length += ft_printhex(args);
	if (format == '%')
		length += ft_printpercentage;
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
}
