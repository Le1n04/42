/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:53:15 by djanssen          #+#    #+#             */
/*   Updated: 2022/09/26 12:45:42 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pt_dst;
	char	*pt_src;

	pt_dst = (char *)dst;
	pt_src = (char *)src;
	if (!len || dst == src)
		return (dst);
	if (pt_src < pt_dst)
	{
		while (len--)
		{
			*(pt_dst + len) = *(pt_src + len);
		}
	}
	else
		while (len--)
			*pt_dst++ = *pt_src++;
	return (dst);
}

// int	main(void)
// {
// 	char	dst[] = "ola";
// 	char	src[] = "lorem ipum dolor sit a";

// 	printf("%s", ft_memmove(dst, src, 8));
// 	return (0);
// }
