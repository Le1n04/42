/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/29 17:43:26 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief This function will make the player move NORTH.
 * 
 * @param map Main struct.
 */
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

/**
 * @brief This function will make the player move SOUTH.
 * 
 * @param map Main struct.
 */
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

/**
 * @brief This function will make the player move WEST.
 * 
 * @param map Main struct.
 */
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

/**
 * @brief This function will make the player move EAST.
 * 
 * @param map Main struct.
 */
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

/**
 * @brief This is the main movement function it will check if there's something
 * different than 1 and will process the move and print the new map.
 * 
 * @param map Main struct.
 * @param k Received parameter from keyhooks function. (WASD - 1234)
 */
void	ft_move(t_map *map, int k)
{
	if (k == 1 && map->matrix[map->player_y - 1][map->player_x] != '1' &&
		!map->game_finished)
	{
		moveup(map);
		ft_print_images(map);
	}
	else if (k == 2 && map->matrix[map->player_y + 1][map->player_x] != '1' &&
				!map->game_finished)
	{
		movedown(map);
		ft_print_images(map);
	}
	else if (k == 3 && map->matrix[map->player_y][map->player_x + 1] != '1' &&
				!map->game_finished)
	{
		moveleft(map);
		ft_print_images(map);
	}
	else if (k == 4 && map->matrix[map->player_y][map->player_x - 1] != '1' &&
				!map->game_finished)
	{
		moveright(map);
		ft_print_images(map);
	}
}
