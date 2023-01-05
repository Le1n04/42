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
void	ft_loadimg(t_map *map, xpm_t **xpm)
{
	map->mlx = mlx_init(map->x_axis * W, map->y_axis * H, "A", false);
	xpm[tile] = mlx_load_xpm42("p/solid/water.xpm42");
	xpm[wall] = mlx_load_xpm42("p/solid/grass.xpm42");
	xpm[topwall] = mlx_load_xpm42("p/solid/grass_top.xpm42");
	xpm[botwall] = mlx_load_xpm42("p/solid/grass_bot.xpm42");
	xpm[blwall] = mlx_load_xpm42("p/solid/corner_bot_left.xpm42");
	xpm[brwall] = mlx_load_xpm42("p/solid/corner_bot_right.xpm42");
	xpm[ulwall] = mlx_load_xpm42("p/solid/corner_top_left.xpm42");
	xpm[urwall] = mlx_load_xpm42("p/solid/corner_top_right.xpm42");
	xpm[leftwall] = mlx_load_xpm42("p/solid/grass_left.xpm42");
	xpm[rightwall] = mlx_load_xpm42("p/solid/grass_right.xpm42");
	xpm[player] = mlx_load_xpm42("p/inter/patito-agua.xpm42");
	xpm[coin] = mlx_load_xpm42("p/inter/flor-agua.xpm42");
	xpm[ext] = mlx_load_xpm42("p/inter/exit_basket.xpm42");
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
void	ft_texturetoimg(t_map *m, xpm_t **xpm, mlx_image_t **img)
{
	img[tile] = mlx_texture_to_image(m->mlx, &xpm[tile]->texture);
	img[wall] = mlx_texture_to_image(m->mlx, &xpm[wall]->texture);
	img[topwall] = mlx_texture_to_image(m->mlx, &xpm[topwall]->texture);
	img[botwall] = mlx_texture_to_image(m->mlx, &xpm[botwall]->texture);
	img[blwall] = mlx_texture_to_image(m->mlx, &xpm[blwall]->texture);
	img[brwall] = mlx_texture_to_image(m->mlx, &xpm[brwall]->texture);
	img[ulwall] = mlx_texture_to_image(m->mlx, &xpm[ulwall]->texture);
	img[urwall] = mlx_texture_to_image(m->mlx, &xpm[urwall]->texture);
	img[leftwall] = mlx_texture_to_image(m->mlx, &xpm[leftwall]->texture);
	img[rightwall] = mlx_texture_to_image(m->mlx, &xpm[rightwall]->texture);
	img[player] = mlx_texture_to_image(m->mlx, &xpm[player]->texture);
	img[ext] = mlx_texture_to_image(m->mlx, &xpm[ext]->texture);
	img[coin] = mlx_texture_to_image(m->mlx, &xpm[coin]->texture);
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
		walls(m, i, j);
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
void	ft_print_images(t_map *m, xpm_t **xpm)
{
	int		i;
	int		j;
	char	*itoad;
	char	*itoad2;

	i = -1;
	itoad = ft_strnjoin("Moves: ", ft_itoa(m->moves), 2);
	itoad2 = ft_strnjoin("Coins: ", ft_itoa(m->cc), 2);
	itoad2 = ft_strnjoin(itoad2, "/", 1);
	itoad2 = ft_strjoin(itoad2, ft_itoa(m->elm.c));
	while (m->matrix[++i] && i < (int)m->y_axis)
	{
		j = -1;
		while (++j >= 0 && j < (int)m->x_axis)
			imageconditioner(m, i, j);
	}
	m->user = mlx_texture_to_image(m->mlx, &xpm[player]->texture);
	mlx_image_to_window(m->mlx, m->user, m->player_x * W, m->player_y * H);
	mlx_put_string(m->mlx, itoad, 0, 0);
	mlx_put_string(m->mlx, itoad2, 128, 0);
	free (itoad);
	free (itoad2);
}

/**
 * @brief This function will initiate every image related function.
 * 
 * @param map Main struct.
 * @return 1 if success, 0 if failure.
 */
void	ft_init_graphics(t_map *map)
{
	ft_loadimg(map, map->xpm);
	ft_texturetoimg(map, map->xpm, map->img);
	ft_print_images(map, map->xpm);
}
