/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigneditoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:38:44 by djanssen          #+#    #+#             */
/*   Updated: 2022/11/14 17:29:37 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief This function will measure 'n' length.
 * 
 * @param n the number to measure.
 * @return Length.
 */
static int	ft_itoalen(unsigned int n)
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
 * @brief "int n" converted to a string 'str'.
 * 
 * @param n the number to be converted.
 * @return The number as a string.
 */
char	*ft_unsigneditoa(unsigned int n)
{
	char			*str;
	unsigned int	len;

	len = ft_itoalen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (n != 0)
	{
		str[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (str);
}
