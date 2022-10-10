/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:11:45 by djanssen          #+#    #+#             */
/*   Updated: 2022/09/26 12:01:47 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*pt_dst;
	char	*pt_src;

	pt_dst = (char *)dst;
	pt_src = (char *)src;
	i = 0;
	if ((pt_dst != NULL) && (pt_src != NULL))
	{
		while (i < n)
		{
			pt_dst[i] = pt_src[i];
			i++;
		}
	}
	return (dst);
}

// int	main(void)
// {
// 	char dst[] = "abcdefg1";
// 	char src[] = "ABCDEF";
// 	printf("%s", ft_memcpy(dst, src, sizeof(src)));
// 	return (0);
// }