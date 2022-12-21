/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/21 18:42:20 by djanssen         ###   ########.fr       */
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
}

int	ft_check_ones(char *tmp)
{
	while (*tmp && *tmp == '1')
		tmp++;
	if (*tmp)
		return (1);
	return (0);
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

// int	ft_check_bne_one(char *tmp)
// {
// 	if (tmp[0] != '1' || tmp[ft_strlen(tmp) - 1] != '1')
// 		return (1);
// 	return (0);
// }

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

void	ft_check_elements(t_map *fmap)
{
	t_elements	elm;

	elm.y = get_height(fmap->path);
	while (elm.y--)
	{
		elm.x = 0;
		while (fmap->matrix[elm.y][elm.x])
		{
			if (fmap->matrix[elm.y][elm.x] == 'E')
				elm.e++;
			else if (fmap->matrix[elm.y][elm.x] == 'P')
				elm.p++;
			else if (fmap->matrix[elm.y][elm.x] == 'C')
				elm.c++;
			else if (fmap->matrix[elm.y][elm.x] != '1' &&
				fmap->matrix[elm.y][elm.x] != '0')
				fmap->error = 5;
			elm.x++;
		}
	}
	if (elm.c == 0 || elm.p == 0 || elm.e == 0 || elm.p > 1)
		fmap->error = 6;
}

t_map	read_map(char *input)
{
	t_map		fmap;
	int			fd;
	size_t		current;
	char		*tmp;

	current = 0;
	init_vars(&fmap, input);
	if (fmap.error)
		return (fmap);
	fmap.matrix = (char **)malloc(fmap.y_axis * sizeof(char *));
	fd = open(fmap.path, O_RDONLY);
	tmp = get_next_line(fd);
	fmap.x_axis = ft_strlen(tmp);
	while (!fmap.error && current < fmap.y_axis)
	{
		ft_check_lines(tmp, current, &fmap);
		fmap.matrix[current] = tmp;
		tmp = get_next_line(fd);
		current++;
	}
	return (close(fd), fmap);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (write(1, ("Error - you must introduce 2 arguments.\n"), 40), 1);
	map = read_map(argv[1]);
	if (map.error)
		ft_print_error(map.error);
	printf("Map path: %s\nMap x, y: %ld, %ld\n", map.path, map.x_axis, map.y_axis);
	return (0);
}
