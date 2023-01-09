/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveright.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/01/09 15:42:32 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	moverightp(t_map *map)
{
	map->matrix[map->player_y][map->player_x - 1] = 'P';
	map->matrix[map->player_y][map->player_x] = '0';
	map->img[player]->instances[0].x -= W;
	map->player_x--;
	ft_print_strings(map);
}

void	moverightc(t_map *map)
{
	map->matrix[map->player_y][map->player_x - 1] = 'P';
	map->matrix[map->player_y][map->player_x] = '0';
	map->img[player]->instances[0].x -= W;
	map->player_x--;
	map->cc++;
	ft_print_strings(map);
}

void	moverighte(t_map *map)
{
	map->matrix[map->player_y][map->player_x - 1] = 'P';
	map->matrix[map->player_y][map->player_x] = '0';
	map->img[player]->instances[0].x -= W;
	map->player_x--;
	map->game_finished++;
	ft_print_strings(map);
	puts("\nYou've won.");
}

/**
 * @brief This function will make the player move WEST.
 * 
 * @param map Main struct.
 */
void	moveright(t_map *map)
{
	map->moves++;
	printf("Move count: %d\n", map->moves);
	if (map->matrix[map->player_y][map->player_x - 1] == '0')
		moverightp(map);
	else if (map->matrix[map->player_y][map->player_x - 1] == 'C')
		moverightc(map);
	else if (map->matrix[map->player_y][map->player_x - 1] == 'E' &&
				map->cc == map->elm.c)
		moverighte(map);
	else if (map->matrix[map->player_y][map->player_x - 1] == 'E' &&
				map->cc != map->elm.c)
	{
		puts("You need to take more coins in order to win.");
		map->moves--;
	}
}
