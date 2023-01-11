/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/01/09 16:44:48 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_directions_enable(t_map *m, int k)
{
	if (k == 1 && !m->game_finished)
	{
		m->img[playerright]->instances[0].enabled = 0;
		m->img[playerleft]->instances[0].enabled = 0;
		m->img[playerdown]->instances[0].enabled = 0;
		m->img[playerup]->instances[0].enabled = 1;
	}
	if (k == 2 && !m->game_finished)
	{
		m->img[playerright]->instances[0].enabled = 0;
		m->img[playerleft]->instances[0].enabled = 0;
		m->img[playerdown]->instances[0].enabled = 1;
		m->img[playerup]->instances[0].enabled = 0;
	}
	if (k == 3 && !m->game_finished)
	{
		m->img[playerright]->instances[0].enabled = 1;
		m->img[playerleft]->instances[0].enabled = 0;
		m->img[playerdown]->instances[0].enabled = 0;
		m->img[playerup]->instances[0].enabled = 0;
	}
	if (k == 4 && !m->game_finished)
	{
		m->img[playerright]->instances[0].enabled = 0;
		m->img[playerleft]->instances[0].enabled = 1;
		m->img[playerdown]->instances[0].enabled = 0;
		m->img[playerup]->instances[0].enabled = 0;
	}
}

/**
 * @brief This is the main movement function it will check if there's something
 * different than 1 and will process the move and print the new map.
 *
 * @param map Main struct.
 * @param k Received parameter from keyhooks function. (WASD - 1234)
 */
void ft_move(t_map *map, int k)
{
	if (k == 1 && map->matrix[map->player_y - 1][map->player_x] != '1' &&
		!map->game_finished)
	{
		moveup(map);
		ft_directions_enable(map, k);
	}
	else if (k == 2 && map->matrix[map->player_y + 1][map->player_x] != '1' &&
			 !map->game_finished)
	{
		movedown(map);
		ft_directions_enable(map, k);
	}
	else if (k == 3 && map->matrix[map->player_y][map->player_x + 1] != '1' &&
			 !map->game_finished)
	{
		moveleft(map);
		ft_directions_enable(map, k);
	}
	else if (k == 4 && map->matrix[map->player_y][map->player_x - 1] != '1' &&
			 !map->game_finished)
	{
		moveright(map);
		ft_directions_enable(map, k);
	}
}
