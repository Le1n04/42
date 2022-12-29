/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/29 16:27:44 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_loadimg(t_map *map, xpm_t **xpm)
{
	map->mlx = mlx_init(map->x_axis * W, map->y_axis * H, "A", false);
	if (!map->mlx)
		return (EXIT_FAILURE);
	xpm[tile] = mlx_load_xpm42("p/water.xpm42");
	if (!xpm[tile])
		return (0);
	xpm[wall] = mlx_load_xpm42("p/grass.xpm42");
	if (!xpm[wall])
		return (0);
	xpm[player] = mlx_load_xpm42("p/duck.xpm42");
	if (!xpm[player])
		return (0);
	xpm[coin] = mlx_load_xpm42("p/flower_open.xpm42");
	if (!xpm[coin])
		return (0);
	xpm[ext] = mlx_load_xpm42("p/exit_basket.xpm42");
	if (!xpm[ext])
		return (0);
	return (1);
}

int	ft_texturetoimg(t_map *m, xpm_t **xpm, mlx_image_t **img)
{
	img[tile] = mlx_texture_to_image(m->mlx, &xpm[tile]->texture);
	if (!img[tile])
		return (0);
	img[wall] = mlx_texture_to_image(m->mlx, &xpm[wall]->texture);
	if (!img[wall])
		return (0);
	img[player] = mlx_texture_to_image(m->mlx, &xpm[player]->texture);
	if (!img[player])
		return (0);
	img[ext] = mlx_texture_to_image(m->mlx, &xpm[ext]->texture);
	if (!img[ext])
		return (0);
	img[coin] = mlx_texture_to_image(m->mlx, &xpm[coin]->texture);
	if (!img[coin])
		return (0);
	return (1);
}

void	ft_print_images(t_map *m)
{
	int		i;
	int		j;
	char	*itoad;

	i = -1;
	itoad = ft_itoa(m->moves);
	while (m->matrix[++i] && i < (int)m->y_axis)
	{
		j = -1;
		while (++j >= 0 && j < (int)m->x_axis)
		{
			if (m->matrix[i][j] == '1')
				mlx_image_to_window(m->mlx, m->img[wall], j * W, i * H);
			if (m->matrix[i][j] == '0')
				mlx_image_to_window(m->mlx, m->img[tile], j * W, i * H);
			if (m->matrix[i][j] == 'P')
				mlx_image_to_window(m->mlx, m->img[player], j * W, i * H);
			if (m->matrix[i][j] == 'E')
				mlx_image_to_window(m->mlx, m->img[ext], j * W, i * H);
			if (m->matrix[i][j] == 'C')
				mlx_image_to_window(m->mlx, m->img[coin], j * W, i * H);
		}
	}
	mlx_put_string(m->mlx, "Moves:", 0, 0);
	mlx_put_string(m->mlx, itoad, 64, 0);
	free (itoad);
}	

int	ft_init_graphics(t_map *map)
{
	ft_loadimg(map, map->xpm);
	ft_texturetoimg(map, map->xpm, map->img);
	ft_print_images(map);
	return (1);
}
