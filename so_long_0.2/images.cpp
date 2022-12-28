/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/28 16:59:04 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_loadimg(xpm_t **xpm)
{
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

int	ft_init_graphics(t_map *map)
{
	if (!ft_loadimg(map->xpm))
		return (0);
	if (!ft_texturetoimg(map, map->xpm, map->img))
		return (0);
	return (1);
}
