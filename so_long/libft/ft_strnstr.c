/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:34:40 by djanssen          #+#    #+#             */
/*   Updated: 2022/10/17 11:11:05 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;
	char	*hay;

	i = 0;
	hay = (char *)haystack;
	needle_len = ft_strlen(needle);
	if (needle_len == 0 || haystack == needle)
		return (hay);
	while (hay[i] && i < len)
	{
		j = 0;
		while (hay[i + j] && needle[j]
			&& hay [i + j] == needle[j] && i + j < len)
			j++;
		if (j == needle_len)
			return (hay + i);
		i++;
	}
	return (NULL);
}

// int	main(void) 
// {
//  	size_t n;
//  	char s1[] = "hola";
//  	char s2[] = "ol";

//  	printf("%s\n", ft_strnstr(s1, s2, 5));
// }
