/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/01/09 16:49:54 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief This function will detect the key that's pressed 
 * and the action (press), if any of the 5 keys (WASD-ESC) is pressed
 * the player will move / game will be closed (ESC).
 * 
 * @param keydata mlx keydata struct.
 * @param param main struct.
 */
void	keyhook1(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS
		&& !map->game_finished)
		ft_move(map, 1);
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS
		&& !map->game_finished)
		ft_move(map, 2);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS
		&& !map->game_finished)
		ft_move(map, 3);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS
		&& !map->game_finished)
		ft_move(map, 4);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(map->mlx);
}

// void	showleaks(void)
// {
// 	system("leaks -q so_long");
// }

/**
 * @brief This is the main function, it will receive the *.ber file
 * and start the program.
 * 
 * @param t_map Main struct. 
 * @param argv Map path.
 * @return 0 - if success.
 */
int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (write(1, ("Error - you must introduce 2 arguments.\n"), 40), 1);
	map = read_map(argv[1]);
	if (ft_print_error(map.error))
		return (EXIT_FAILURE);
	ft_check_elements(&map);
	ft_where_is_player(&map);
	if (!map.error)
	{
		ft_init_graphics(&map);
		mlx_key_hook(map.mlx, &keyhook1, &map);
		mlx_loop(map.mlx);
	}
	return (EXIT_SUCCESS);
}

/**
 * SEG FAULT CON 0 EN ESQUINA
 * 
 * 
 * Hacer que el player se printee un tile de agua
 * , que sea una g_img como al principio y
 * que la imagen printeada solo se vuelva a printear
 * cuando pillas un objeto. (replantear movimiento supongo).
 * 
 * ?? Hacer que se saquen mas errores si falla algo de texturas ??
 * ?? Error management para CADA tipo ??
 * 
 * Programar enemigo.
 * 
 */