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

#include "../../so_long.h"

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

/**
 * @brief This function will print every image and the move counter
 *  into the MLX instance.
 * 
 * @param m Main struct.
 */
void	ft_print_images(t_map *m, xpm_t **xpm)
{
	int		i;
	int		j;

	i = -1;
	while (m->matrix[++i] && i < (int)m->y_axis)
	{
		j = -1;
		while (++j >= 0 && j < (int)m->x_axis)
		{
			if (m->matrix[i][j] == '1')
				walls(m, i, j);
			if (m->matrix[i][j] == '0' || m->matrix[i][j] == 'P'
				|| m->matrix[i][j] == 'C')
				mlx_image_to_window(m->mlx, m->img[tile], j * W, i * H);
			if (m->matrix[i][j] == 'E')
				mlx_image_to_window(m->mlx, m->img[ext], j * W, i * H);
		}
	}
}

void	ft_print_objects(t_map *m, xpm_t **xpm)
{
	mlx_image_to_window(m->mlx, m->img[player],
		m->player_x * W, m->player_y * H);
}

void	ft_print_strings(t_map *m)
{
	char	*itoad;
	char	*itoad2;

	itoad = ft_strnjoin("Moves: ", ft_itoa(m->moves), 2);
	itoad2 = ft_strnjoin("Coins: ", ft_itoa(m->cc), 2);
	itoad2 = ft_strnjoin(itoad2, "/", 1);
	itoad2 = ft_strjoin(itoad2, ft_itoa(m->elm.c));
	mlx_put_string(m->mlx, itoad, 0, 0);
	mlx_put_string(m->mlx, itoad2, 128, 0);
	free (itoad);
	free (itoad2);
}
