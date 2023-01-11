/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveright.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/01/10 12:54:39 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	moverightp(t_map *map)
{
	map->matrix[map->player_y][map->player_x - 1] = 'P';
	map->matrix[map->player_y][map->player_x] = '0';
	map->img[playerright]->instances[0].x -= W;
	map->img[playerleft]->instances[0].x -= W;
	map->img[playerup]->instances[0].x -= W;
	map->img[playerdown]->instances[0].x -= W;
	map->player_x--;
	ft_print_strings(map);
}

void	moverightc(t_map *map)
{
	int	i;

	i = -1;
	map->matrix[map->player_y][map->player_x - 1] = 'P';
	map->matrix[map->player_y][map->player_x] = '0';
	map->img[playerright]->instances[0].x -= W;
	map->img[playerleft]->instances[0].x -= W;
	map->img[playerup]->instances[0].x -= W;
	map->img[playerdown]->instances[0].x -= W;
	map->player_x--;
	map->cc++;
	while (++i < map->elm.c)
	{
		if (map->img[coin0]->instances[i].x == (int32_t)map->player_x * W
			&& (int32_t)map->player_y * H == map->img[coin0]->instances[i].y)
			map->img[coin0]->instances[i].enabled = 0;
	}
	ft_print_strings(map);
}

void	moverighte(t_map *map)
{
	map->matrix[map->player_y][map->player_x - 1] = 'P';
	map->matrix[map->player_y][map->player_x] = '0';
	map->img[playerright]->instances[0].x -= W;
	map->img[playerleft]->instances[0].x -= W;
	map->img[playerup]->instances[0].x -= W;
	map->img[playerdown]->instances[0].x -= W;
	map->player_x--;
	map->game_finished++;
	ft_print_strings(map);
	puts("\nYou've won.");
}

void	moverightenemy(t_map *map)
{
	map->matrix[map->player_y][map->player_x] = '0';
	map->img[playerleft]->instances[0].enabled = 0;
	map->img[playerup]->instances[0].enabled = 0;
	map->img[playerdown]->instances[0].enabled = 0;
	map->img[playerright]->instances[0].enabled = 0;
	map->game_finished++;
	puts("\nYou died.");
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
	else if (map->matrix[map->player_y][map->player_x - 1] == 'V')
		moverightenemy(map);
	else if (map->matrix[map->player_y][map->player_x - 1] == 'E' &&
				map->cc != map->elm.c)
	{
		puts("You need to take more coins in order to win.");
		map->moves--;
	}
}
