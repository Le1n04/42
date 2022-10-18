/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:37:36 by djanssen          #+#    #+#             */
/*   Updated: 2022/10/18 18:44:40 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*pt_src;
	size_t	i;
	size_t	len_dst;
	size_t	len_src;
	size_t	res;

	pt_src = (char *)src;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(pt_src);
	res = 0;
	i = 0;
	if (dstsize > len_dst)
		res = len_src + len_dst;
	else
		res = len_src + dstsize;
	while (pt_src[i] && (len_dst + 1) < dstsize)
	{
		dst[len_dst] = pt_src[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = '\0';
	return (res);
}
/*
int	main(void)
{
	char	dst[];
	char	src[];

    dst[] = "123456789";
    src[] = "inicio";
    printf("%zu\n", ft_strlcat(dst, src, sizeof(dst)));
    printf("%zu", strlcat(dst, src, sizeof(dst)));
    return (0);
}
*/
