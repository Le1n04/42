/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:27:54 by djanssen          #+#    #+#             */
/*   Updated: 2022/10/06 19:40:55 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int j;
	unsigned int *num;

	i = 0;
	j = 0;
	if (nptr[0] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i])
	{
		if (nptr[i] <= '0' && nptr[i] >= '9')
			return (0);
		else
			{
				num[j] = nptr[i];
				j++;
				i++;
			}
	}
	return (num);
}

int main(void)
{
 	char s1[] = "hola";

 	printf("%d\n", ft_atoi(s1));
}