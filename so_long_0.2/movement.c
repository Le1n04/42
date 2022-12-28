/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/28 12:13:21 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moveup(t_map *map)
{
	map->moves++;
	printf("Move count: %d\n", map->moves);
	if (map->matrix[map->player_y - 1][map->player_x] == '0')
	{
		map->matrix[map->player_y - 1][map->player_x] = 'P';
		map->matrix[map->player_y][map->player_x] = '0';
		map->player_y--;
	}
	else if (map->matrix[map->player_y - 1][map->player_x] == 'C')
	{
		map->matrix[map->player_y - 1][map->player_x] = '0';
		map->cc++;
	}
	else if (map->matrix[map->player_y - 1][map->player_x] == 'E' &&
				map->cc == map->elm.c)
	{
		map->matrix[map->player_y - 1][map->player_x] = 'P';
		map->matrix[map->player_y][map->player_x] = '0';
		map->player_y++;
		map->game_finished++;
		puts("\nYou've won.");
	}
	else if (map->matrix[map->player_y - 1][map->player_x] == 'E' &&
				map->cc != map->elm.c)
		puts("You need to take more coins in order to win.");
}

void	movedown(t_map *map)
{
	map->moves++;
	printf("Move count: %d\n", map->moves);
	if (map->matrix[map->player_y + 1][map->player_x] == '0')
	{
		map->matrix[map->player_y + 1][map->player_x] = 'P';
		map->matrix[map->player_y][map->player_x] = '0';
		map->player_y++;
	}
	else if (map->matrix[map->player_y + 1][map->player_x] == 'C')
	{
		map->matrix[map->player_y + 1][map->player_x] = '0';
		map->cc++;
	}
	else if (map->matrix[map->player_y + 1][map->player_x] == 'E' &&
				map->cc == map->elm.c)
	{
		map->matrix[map->player_y + 1][map->player_x] = 'P';
		map->matrix[map->player_y][map->player_x] = '0';
		map->player_y++;
		map->game_finished++;
		puts("\nYou've won.");
	}
	else if (map->matrix[map->player_y + 1][map->player_x] == 'E' &&
				map->cc != map->elm.c)
		puts("You need to take more coins in order to win.");
}

void	moveleft(t_map *map)
{
	map->moves++;
	printf("Move count: %d\n", map->moves);
	if (map->matrix[map->player_y][map->player_x + 1] == '0')
	{
		map->matrix[map->player_y][map->player_x + 1] = 'P';
		map->matrix[map->player_y][map->player_x] = '0';
		map->player_x++;
	}
	else if (map->matrix[map->player_y][map->player_x + 1] == 'C')
	{
		map->matrix[map->player_y][map->player_x + 1] = '0';
		map->cc++;
	}
	else if (map->matrix[map->player_y][map->player_x + 1] == 'E' &&
				map->cc == map->elm.c)
	{
		map->matrix[map->player_y][map->player_x + 1] = 'P';
		map->matrix[map->player_y][map->player_x] = '0';
		map->player_x++;
		map->game_finished++;
		puts("\nYou've won.");
	}
	else if (map->matrix[map->player_y][map->player_x + 1] == 'E' &&
				map->cc != map->elm.c)
		puts("You need to take more coins in order to win.");
}

void	moveright(t_map *map)
{
	map->moves++;
	printf("Move count: %d\n", map->moves);
	if (map->matrix[map->player_y][map->player_x - 1] == '0')
	{
		map->matrix[map->player_y][map->player_x - 1] = 'P';
		map->matrix[map->player_y][map->player_x] = '0';
		map->player_x--;
	}
	else if (map->matrix[map->player_y][map->player_x - 1] == 'C')
	{
		map->matrix[map->player_y][map->player_x - 1] = '0';
		map->cc++;
	}
	else if (map->matrix[map->player_y][map->player_x - 1] == 'E' &&
				map->cc == map->elm.c)
	{
		map->matrix[map->player_y][map->player_x - 1] = 'P';
		map->matrix[map->player_y][map->player_x] = '0';
		map->player_x--;
		map->game_finished++;
		puts("\nYou've won.");
	}
	else if (map->matrix[map->player_y][map->player_x - 1] == 'E' &&
				map->cc != map->elm.c)
		puts("You need to take more coins in order to win.");
}

void	ft_move(t_map *map, int k)
{
	if (k == 1 && map->matrix[map->player_y - 1][map->player_x] != '1' &&
		!map->game_finished)
	{
		moveup(map);
		ft_print_map(map);
	}
	else if (k == 2 && map->matrix[map->player_y + 1][map->player_x] != '1' &&
				!map->game_finished)
	{
		movedown(map);
		ft_print_map(map);
	}
	else if (k == 3 && map->matrix[map->player_y][map->player_x + 1] != '1' &&
				!map->game_finished)
	{
		moveleft(map);
		ft_print_map(map);
	}
	else if (k == 4 && map->matrix[map->player_y][map->player_x - 1] != '1' &&
				!map->game_finished)
	{
		moveright(map);
		ft_print_map(map);
	}
}
