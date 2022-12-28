/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/28 12:19:44 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	get_height(char *input)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	fd = open(input, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	return (free(tmp), close(fd), i);
}

void	init_vars(t_map *fmap, char *input)
{
	fmap->error = 0;
	fmap->path = ft_strdup(input);
	fmap->x_axis = 0;
	fmap->y_axis = get_height(fmap->path);
	if (!fmap->y_axis)
		fmap->error = 1;
	fmap->elm.c = 0;
	fmap->elm.e = 0;
	fmap->elm.p = 0;
	fmap->cc = 0;
}
