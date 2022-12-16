/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maincuadrao.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/16 12:31:09 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define BPP sizeof(int32_t)

void	img_init(mlx_t	*mlx)
{
	mlx_image_t* img = mlx_new_image(mlx, 60, 60);

	memset(img->pixels, 255, img->width * img->height * BPP);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_image_to_window(mlx, img, 60, 0);
}

static void	init_vars(t_vars *vars)
{
	vars->collect = 0;
	vars->movement = 0;
	vars->win_w = ft_strlen(vars->map[0]);
	vars->win_h = get_height(vars->map);
}

int32_t	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc <= 1)
	{
		perror("error");
		exit (1);
	}
	(void)argv;
	vars.map = get_map(argv[1]);
	vars.mlx = mlx_init(vars.win_w, vars.win_h, "LIVE REACTION:", false);
	if (!vars.mlx)
		exit(EXIT_FAILURE);
	if (vars.map != NULL)
	{
		img_init(vars.mlx);
		mlx_key_hook(vars.mlx, &keyhook2, NULL);
		mlx_loop(vars.mlx);
		mlx_terminate(vars.mlx);
		return (EXIT_SUCCESS);
	}
}
	// mlx_loop_hook(mlx, &key_hooks, mlx);
	// memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	