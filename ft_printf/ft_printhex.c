/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:12:30 by djanssen          #+#    #+#             */
/*   Updated: 2022/11/07 17:24:22 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/**
 * @brief Get len of 'n' to return it right after.
 * 
 * @param n number given.
 * @return len of 'n'.
 */
int	ft_lenhex(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
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
void	ft_get_hex(int n, const char format)
{
	if (n >= 16)
	{
		ft_get_hex(n / 16, format);
		ft_get_hex(n % 16, format);
	}
	else
	{
		
	}
}

int	ft_printhex(int h)
{
	
}
