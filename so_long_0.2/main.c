/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/20 14:48:41 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	read_map(char *input)
{
	t_map	fmap;
	int		fd;
	size_t	i;
	char	*map_name;

	fmap.path = ft_strdup(input);
	fmap.x_axis = ft_strlen()
}

int32_t	main(int argc, char **argv)
{
	if (argc != 2)
		return (printf("Error - you must introduce 2 arguments."), 1);
	read_map();
}
