/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/29 18:00:15 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief This function will load every '*.xpm42' into their correspondent 
 * 'xpm[IMG_COUNT]' as textures. 
 * 
 * @param map Main struct.
 * @param xpm Struct containing data regarding an XPM image.
 * @return 0 if failure, 1 if success.
 */
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

/**
 * @brief This function will convert textures from 'ft_loadimg' to images
 * into their correspondent 'img[IMG_COUNT]'.
 * 
 * @param m Main struct.
 * @param xpm Struct containing data regarding an XPM image.
 * @param img An image that can be rendered.
 * @return 1 if success, 0 if failure.
 */
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

/**
 * @brief This function is a complement of 'ft_print_images'.
 * It will draw an instance of the images.
 * 
 * @param m Main struct.
 * @param i counter from 'ft_print_images'.
 * @param j counter from 'ft_print_images'.
 */
void	imageconditioner(t_map *m, int i, int j)
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

/**
 * @brief This function will print every image and the move counter
 *  into the MLX instance.
 * 
 * @param m Main struct.
 */
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
			imageconditioner(m, i, j);
	}
	mlx_put_string(m->mlx, "Moves:", 0, 0);
	mlx_put_string(m->mlx, itoad, 64, 0);
	free (itoad);
}	

/**
 * @brief This function will initiate every image related function.
 * 
 * @param map Main struct.
 * @return 1 if success, 0 if failure.
 */
int	ft_init_graphics(t_map *map)
{
	if (!ft_loadimg(map, map->xpm))
		return (0);
	if (!ft_texturetoimg(map, map->xpm, map->img))
		return (0);
	ft_print_images(map);
	return (1);
}
