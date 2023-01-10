/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/01/10 12:56:54 by djanssen         ###   ########.fr       */
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
	int	i;

	i = -1;
	map->matrix[map->player_y - 1][map->player_x] = 'P';
	map->matrix[map->player_y][map->player_x] = '0';
	map->player_y--;
	map->img[player]->instances[0].y -= H;
	map->cc++;
	while (++i < map->elm.c)
	{
		if (map->img[coin0]->instances[i].x == (int32_t)map->player_x * W
			&& (int32_t)map->player_y * H == map->img[coin0]->instances[i].y)
			map->img[coin0]->instances[i].enabled = 0;
	}
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

void	moveupenemy(t_map *map)
{
	map->matrix[map->player_y][map->player_x] = '0';
	map->img[player]->instances[0].enabled = 0;
	map->game_finished++;
	puts("\nYou died.");
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
	else if (map->matrix[map->player_y - 1][map->player_x] == 'V')
		moveupenemy(map);
	else if (map->matrix[map->player_y - 1][map->player_x] == 'E' &&
				map->cc != map->elm.c)
	{
		puts("You need to take more coins in order to win.");
		map->moves--;
	}
}
