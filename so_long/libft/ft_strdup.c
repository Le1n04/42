/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:18:41 by djanssen          #+#    #+#             */
/*   Updated: 2022/11/22 14:07:16 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (src[++i])
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char	*src;
// 	char	*new;

// 	src = "hola k ase";
// 	printf("%s", ft_strdup(src));
// }
