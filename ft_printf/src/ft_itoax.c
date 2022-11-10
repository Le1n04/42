/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:12:30 by djanssen          #+#    #+#             */
/*   Updated: 2022/11/07 14:04:25 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Get n length.
 * 
 * @param n number given.
 * @return length of param n.
 */
static long int	ft_len(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

/**
 * @brief Convert integer 'n' to alphabet value.
 * 
 * @param n number received.
 * @return 'n' param converted to string 'x'.
 */
char	*ft_itoax(unsigned int n)
{
	char		*x;
	long int	len;

	len = ft_len(n);
	x = (char *)malloc(sizeof(char) * (len + 1));
	if (!x)
		return (NULL);
	x[len] = '\0';
	while (n != 0)
	{
		x[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (x);
}
