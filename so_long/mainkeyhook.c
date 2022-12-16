/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainkeyhook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/14 19:09:59 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keyhook2(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (keydata.key == MLX_KEY_H && keydata.action == MLX_PRESS)
		puts("Hello");
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_RELEASE)
		puts("World");
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_REPEAT)
		puts("!");
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE
		&& keydata.modifier == MLX_CONTROL)
		puts("Mariwanero");
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
}

int32_t	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "HOLA MUNDO", true);
	if (!mlx)
		return (EXIT_FAILURE);
	mlx_key_hook(mlx, &keyhook2, NULL);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_FAILURE);
}
