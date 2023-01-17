/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:51:58 by djanssen          #+#    #+#             */
/*   Updated: 2022/10/17 10:54:37 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*string;
	void			*matching_byte;

	i = 0;
	string = (unsigned char *)s;
	matching_byte = NULL;
	while (i < n)
	{
		if (string[i] == (unsigned char)c)
		{
			matching_byte = &string[i];
			break ;
		}
		i++;
	}
	return (matching_byte);
}
