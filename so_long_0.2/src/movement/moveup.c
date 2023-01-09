/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/01/09 17:08:02 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	moveupp(t_map *map)
{
	map->matrix[map->player_y - 1][map->player_x] = 'P';
	map->matrix[map->player_y][map->player_x] = '0';
	map->img[player]->instances[0].y -= H;
	map->player_y--;
	ft_print_strings(map);
}

void	moveupc(t_map *map)
{
	map->matrix[map->player_y - 1][map->player_x] = 'P';
	map->matrix[map->player_y][map->player_x] = '0';
	map->player_y--;
	map->img[player]->instances[0].y -= H;
	map->cc++;
	ft_print_strings(map);
}

void	moveupe(t_map *map)
{
	map->matrix[map->player_y - 1][map->player_x] = 'P';
	map->matrix[map->player_y][map->player_x] = '0';
	map->img[player]->instances[0].y -= H;
	map->player_y++;
	map->game_finished++;
	ft_print_strings(map);
	puts("\nYou've won.");
}

void	moveupex(t_map *map)
{
	puts("You need to take more coins in order to win.");
	map->moves--;
}

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
		moveupp(map);
	else if (map->matrix[map->player_y - 1][map->player_x] == 'C')
		moveupc(map);
	else if (map->matrix[map->player_y - 1][map->player_x] == 'E' &&
				map->cc == map->elm.c)
		moveupe(map);
	else if (map->matrix[map->player_y - 1][map->player_x] == 'E' &&
				map->cc != map->elm.c)
		moveupex(map);
}
