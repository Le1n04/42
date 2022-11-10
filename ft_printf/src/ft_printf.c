/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:12:30 by djanssen          #+#    #+#             */
/*   Updated: 2022/11/10 12:46:48 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Function to print a character when '%c' is called.
 * 
 * @param c character to be printed.
 * @return value 1 as the function only prints a character.
 */
int	ft_printchar(char c)
{
	write (1, &c, 1);
	return (1);
}

/**
 * @brief Function to be called when '%' appears.
 * It will detect and use the function that's needed for each case.
 * @param ap arguments to be processed using 'va_arg'.
 * @param format param to read the character after the percentage symbol.
 * @return length of the print.
 */
int	ft_format(va_list ap, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_printchar(va_arg(ap, int));
	else if (format == 's')
		length += ft_printstr(va_arg(ap, char *));
	else if (format == 'd' || format == 'i')
		length += ft_printnbr(va_arg(ap, int));
	else if (format == 'u')
		length += ft_printunsigned(va_arg(ap, int));
	else if (format == '%')
		length += ft_printpercentage();
	else if (format == 'x' || format == 'X')
		length += ft_printhex(va_arg(ap, unsigned int), format);
	else if (format == 'p')
		length += ft_printpointer(va_arg(ap, unsigned long long));
	return (length);
}

/**
 * @brief This is the main function.
 * 
 * @param va_start macro called first initialising args.
 * @param ... all the params to be included when using (ft_print). 
 * @return length of the function's print.
 */
int	ft_printf(char const *format, ...)
{
	int		i;
	int		length;
	va_list	args;

	va_start(args, format);
	i = 0;
	length = 0;
	while (format[i])
	{
		if (format[i] == '%')
			length += ft_format(args, format[i + 1]);
		else
			length += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (length);
}
