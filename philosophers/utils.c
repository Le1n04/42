/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/03/27 15:42:27 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = -1;
	sign = 1;
	res = 0;
	while (str[++i])
	{
		if (str[0] == '-')
			sign = -1;
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
	}
	return (sign * res);
}
