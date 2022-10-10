/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:18:50 by djanssen          #+#    #+#             */
/*   Updated: 2022/10/04 18:09:30 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = (char)c;
		i++;
	}
	return (b);
}

// int    main(void)
// {
//     char *b1 = (char*)malloc(sizeof(char) * (0xF0000 + 1));
//     *b1 = 0;
//     ft_memset(b1, 'A', 9);
//     printf("%s", b1);
// }
