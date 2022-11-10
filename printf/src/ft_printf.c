/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:48:59 by djanssen          #+#    #+#             */
/*   Updated: 2022/11/10 16:30:50 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief This function will be working when ft_format is called in
 * the ft_printf function - it will look for the 'cspdiuxX%' format.
 *  
 * @return length to be summed in 'ft_printf()' 
 */
int	ft_format(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_printchar(va_arg(args, int));
	else if (format == '%')
		length += ft_printpercentage();
	else if (format == 's')
		length += ft_printstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		length += ft_printnbr(va_arg(args, int));
	return (length);
}

/**
 * @brief Main function, it will read if there's a '%' and go format
 * or just print the char it finds.
 * 
 * @param format 
 * @param ... 
 * @return int 
 */
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
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
			length += ft_format(args, format[++i]);
		else
			length += ft_printchar(format[i]);
	}
	va_end(args);
	return (length);
}

// int	main(void)
// {
// 	ft_printf("hola%c", 't');
// }