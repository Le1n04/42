/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:18:41 by djanssen          #+#    #+#             */
/*   Updated: 2022/10/10 14:29:24 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		ft_strlcpy(new, s1, ft_strlen(s1) + 1);
		ft_strlcat(new, s2, size + 1);
		return (new);
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;

// 	s1 = "hola";
// 	s2 = "adios";
// 	printf("%s", ft_strjoin(s1, s2));
// }
