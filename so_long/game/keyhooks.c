/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/12 18:52:12 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_image_t	*g_img;

void	key_hooks(void *param)
{
	mlx_t	*mlx;
	int		i;

	mlx = param;
	i = 0;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	else if (mlx_is_key_down(mlx, MLX_KEY_R))
		mlx_draw_texture(g_img, mlx_load_png("pngs/:o.png"), 0, 0);
	if (mlx_is_key_down(mlx, MLX_KEY_UP || MLX_KEY_W))
		g_img->instances[0].y -= 5;
	else if (mlx_is_key_down(mlx, MLX_KEY_DOWN || MLX_KEY_S))
		g_img->instances[0].y += 5;
	else if (mlx_is_key_down(mlx, MLX_KEY_LEFT || MLX_KEY_A))
		g_img->instances[0].x -= 5;
	else if (mlx_is_key_down(mlx, MLX_KEY_RIGHT || MLX_KEY_D))
		g_img->instances[0].x += 5;
}
