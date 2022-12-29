/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/29 16:33:49 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (write(1, ("Error - you must introduce 2 arguments.\n"), 40), 1);
	map = read_map(argv[1]);
	ft_where_is_player(&map);
	if (map.error)
		ft_print_error(map.error);
	if (!map.error)
	{
		ft_init_graphics(&map);
		mlx_key_hook(map.mlx, &keyhook1, &map);
		mlx_loop(map.mlx);
	}
	return (EXIT_SUCCESS);
}

// void	showleaks(void)
// {
// 	system("leaks -q so_long");
// }
