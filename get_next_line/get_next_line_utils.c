/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:12:30 by djanssen          #+#    #+#             */
/*   Updated: 2022/10/19 18:29:55 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		size1;
	int		size2;
	int		size;

	if (s1 && s2)
	{
		size1 = 0;
		size2 = 0;
		while (s1[size1])
			size1++;
		while (s2[size2])
			size2++;
		size = size1 + size2;
		new = malloc(sizeof(char) * (size + 1));
		if (!new)
			return (NULL);
		ft_strlcpy(new, s1, ft_strlen(s1) + 1);
		ft_strlcat(new, s2, size + 1);
		return (new);
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	new = malloc(sizeof(char) * (size + 1));
	if (!(new))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*pt_src;

	pt_src = (char *)src;
	i = 0;
	if (dstsize > 0)
	{
		while (pt_src[i] && i < dstsize - 1)
		{
			dst[i] = pt_src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

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
