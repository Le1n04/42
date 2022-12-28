/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/28 12:13:18 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_ones(char *tmp)
{
	while (*tmp && *tmp == '1')
		tmp++;
	if (*tmp)
		return (1);
	return (0);
}

void	ft_where_is_player(t_map *fmap)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (++i < (int)fmap->y_axis && !fmap->error)
	{
		j = -1;
		while (++j < (int)fmap->x_axis && !fmap->error)
		{
			if (fmap->matrix[i][j] == 'P' && !fmap->error)
			{
				if (++count == 1)
				{
					fmap->player_x = (size_t)j;
					fmap->player_y = (size_t)i;
				}
			}
		}
	}
	if (!count && !fmap->error)
		fmap->error = 5;
}

int	ft_print_error(int error)
{
	if (error == 1)
		return (printf("Error no.1: Empty map\n"), 1);
	if (error == 2)
		return (printf("Error no.2: Invalid map structure\n"), 1);
	if (error == 3)
		return (printf("Error no.3: Map can't be symetrical\n"), 1);
	if (error == 4)
		return (printf("Error no.4: Map has different X sizes\n"));
	if (error == 5)
		return (printf("Error no.5: Invalid map element\n"), 1);
	if (error == 6)
		return (printf("Error no.6: Not enough map elements\n"), 1);
	return (0);
}

void	ft_check_lines(char *tmp, size_t current, t_map *fmap)
{
	if (fmap->x_axis != ft_strlen(tmp))
		fmap->error = 4;
	if ((current == 0 || current == fmap->y_axis - 1) && ft_check_ones(tmp))
		fmap->error = 2;
	else if (tmp[0] != '1' || tmp[ft_strlen(tmp) - 1] != '1')
		fmap->error = 2;
	if (fmap->x_axis == fmap->y_axis)
		fmap->error = 3;
}

void	ft_check_elements(t_map *map)
{
	map->elm.y = get_height(map->path);
	while (map->elm.y--)
	{
		map->elm.x = 0;
		while (map->matrix[map->elm.y][map->elm.x])
		{
			if (map->matrix[map->elm.y][map->elm.x] == 'E')
				map->elm.e++;
			else if (map->matrix[map->elm.y][map->elm.x] == 'P')
				map->elm.p++;
			else if (map->matrix[map->elm.y][map->elm.x] == 'C')
				map->elm.c++;
			else if (map->matrix[map->elm.y][map->elm.x] != '1' &&
						map->matrix[map->elm.y][map->elm.x] != '0')
				map->error = 5;
			map->elm.x++;
		}
	}
	if (map->elm.c == 0 || map->elm.p == 0 || map->elm.e == 0 || map->elm.p > 1)
		map->error = 6;
}
