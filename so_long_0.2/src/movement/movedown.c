/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movedown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/01/09 16:53:19 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	movedownp(t_map *map)
{
	map->matrix[map->player_y + 1][map->player_x] = 'P';
	map->matrix[map->player_y][map->player_x] = '0';
	map->img[player]->instances[0].y += H;
	map->player_y++;
	ft_print_strings(map);
}

void	movedownc(t_map *map)
{
	map->matrix[map->player_y + 1][map->player_x] = 'P';
	map->matrix[map->player_y][map->player_x] = '0';
	map->img[player]->instances[0].y += H;
	map->player_y++;
	map->cc++;
	ft_print_strings(map);
}

void	movedowne(t_map *map)
{
	map->matrix[map->player_y + 1][map->player_x] = 'P';
	map->matrix[map->player_y][map->player_x] = '0';
	map->img[player]->instances[0].y += H;
	map->player_y++;
	map->game_finished++;
	ft_print_strings(map);
	puts("\nYou've won.");
}

void	movedown(t_map *map)
{
	map->moves++;
	printf("Move count: %d\n", map->moves);
	if (map->matrix[map->player_y + 1][map->player_x] == '0')
		movedownp(map);
	else if (map->matrix[map->player_y + 1][map->player_x] == 'C')
		movedownc(map);
	else if (map->matrix[map->player_y + 1][map->player_x] == 'E' &&
				map->cc == map->elm.c)
		movedowne(map);
	else if (map->matrix[map->player_y + 1][map->player_x] == 'E' &&
				map->cc != map->elm.c)
	{
		puts("You need to take more coins in order to win.");
		map->moves--;
	}
}
