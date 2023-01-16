/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:10:07 by djanssen          #+#    #+#             */
/*   Updated: 2022/10/19 11:34:34 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (n--)
	{
		if (*ss1 != *ss2)
			return ((int)(*ss1 - *ss2));
		ss1++;
		ss2++;
	}
	return (0);
}

// int	main(void)
// {
// size_t n;
// char s1[] = "hola";
// char s2[] = "hola";

// printf("%d\n", ft_memcmp(s1, s2, 4));
// }