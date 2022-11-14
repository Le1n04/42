/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:14:00 by djanssen          #+#    #+#             */
/*   Updated: 2022/11/14 18:51:17 by djanssen         ###   ########.fr       */
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
 * @brief 
 * 
 * @param n 
 */
void	ft_getpointer(uintptr_t n)
{
	if (n >= 16)
	{
		ft_getpointer(n / 16);
		ft_getpointer(n % 16);
	}
}
