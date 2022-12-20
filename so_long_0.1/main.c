/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/19 17:41:57 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_vars *vars)
{
	int	y1;
	int	y_map;
	int	backup_w;
	int	x1;
	int	x_map;

	y1 = 0;
	y_map = 0;
	backup_w = vars->win_w;
	while (vars->win_h > 0)
	{
		x1 = 0;
		x_map = 0;
		while (vars->win_w > 0)
		{
			put_image_to_map(vars->map[y_map][x_map], x1, y1, &vars);
			x_map++;
			x1 += 64;
			vars->win_h--;
		}
		vars->win_w = backup_w;
		y_map++;
		y1 += 64;
		vars->win_h--;
	}
}

static void	init_vars(t_vars *vars)
{
	vars->win_w = ft_strlen(vars->map[0]);
	vars->win_h = get_height(vars->map);
}

int32_t	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc <= 1)
	{
		perror("wowowo");
		exit (1);
	}
	(void)argv;
	vars.map = get_map(argv[1]);
	if (vars.map != NULL)
	{
		init_vars(&vars);
		vars.mlx = mlx_init(vars.win_w * 64, vars.win_h * 64, "so_long", false);
		render_map(&vars);
		mlx_loop(vars.mlx);
	}
	return (EXIT_SUCCESS);
}
	// mlx_loop_hook(mlx, &key_hooks, mlx);
	// memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	//
	//void	img_init(mlx_t	*mlx)
// {
// 	mlx_image_t* img = mlx_new_image(mlx, 60, 60);
//		mlx_key_hook(vars.mlx, &keyhook2, NULL);
// 	memset(img->pixels, 255, img->width * img->height * BPP);
// 	mlx_image_to_window(mlx, img, 0, 0);
// 	mlx_image_to_window(mlx, img, 60, 0);
// }		mlx_terminate(vars.mlx);