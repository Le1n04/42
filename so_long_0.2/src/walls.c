/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/29 18:00:15 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * 1. individuales.
*/
// void	innerwalls(t_map *m, int i, int j)
// {
	// if (m->matrix[i][j - 1] != '1' && m->matrix[i + 1][j] != '1' &&
	// 		m->matrix[i][j + 1] != '1' && m->matrix[i - 1][j] != '1')
	// 	mlx_image_to_window(m->mlx, m->img[botwall], j * W, i * H);
	// if (m->matrix[i][j - 1] != '1' && m->matrix[i + 1][j] != '1' &&
	// 		m->matrix[i][j + 1] != '1')
	// 	mlx_image_to_window(m->mlx, m->img[topwall], j * W, i * H);
//}

/**
 * @brief This function will print the map's walls.
 * 
 * @param m Main struct.
*/
void	walls(t_map *m, int i, int j)
{
	if (i == 0 && j != 0 && j != m->x_axis - 1 && m->matrix[i + 1][j] != '1')
		mlx_image_to_window(m->mlx, m->img[topwall], j * W, i * H);
	else if (i == m->y_axis - 1 && j != 0 && j != m->x_axis - 1)
		mlx_image_to_window(m->mlx, m->img[botwall], j * W, i * H);
	else if (j == 0 && i != 0 && i != m->y_axis - 1)
		mlx_image_to_window(m->mlx, m->img[leftwall], j * W, i * H);
	else if (j == m->x_axis - 1 && i != 0 && i != m->y_axis - 1)
		mlx_image_to_window(m->mlx, m->img[rightwall], j * W, i * H);
	else if (j == 0 && i == 0)
		mlx_image_to_window(m->mlx, m->img[ulwall], j * W, i * H);
	else if (j == m->x_axis - 1 && i == 0)
		mlx_image_to_window(m->mlx, m->img[urwall], j * W, i * H);
	else if (j == 0 && i == m->y_axis - 1)
		mlx_image_to_window(m->mlx, m->img[blwall], j * W, i * H);
	else if (j == m->x_axis - 1 && i == m->y_axis - 1)
		mlx_image_to_window(m->mlx, m->img[brwall], j * W, i * H);
	else if (m->matrix [i + 1][j] != '1')
		mlx_image_to_window(m->mlx, m->img[topwall], j * W, i * H);
	else
		mlx_image_to_window(m->mlx, m->img[wall], j * W, i * H);
}
