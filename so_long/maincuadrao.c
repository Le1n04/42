/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maincuadrao.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/14 18:18:27 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define BPP sizeof(int32_t)

int32_t	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "LIVE REACTION:", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx_image_t* img = mlx_new_image(mlx, 128, 128);
	memset(img->pixels, 255, img->width * img->height * BPP);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
	// mlx_loop_hook(mlx, &key_hooks, mlx);
	// memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	