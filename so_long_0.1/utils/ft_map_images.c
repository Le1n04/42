/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/20 11:47:49 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image(t_vars ***v, int x, int y, char *img)
{
	(**v)->img = mlx_texture_to_image((**v)->mlx, mlx_load_xpm42("img"));
	mlx_image_to_window((**v)->mlx, (**v)->img, x, y);
	mlx_texture_area_to_image
}

void	put_image_to_map(char p, int x1, int y1, t_vars **v)
{
	if (p == '1')
		put_image(&v, x1, y1, "./pngs/pillar.xpm42");
}

// void	put_image_to_map(char p, int x1, int y1, t_vars **v)
// {
// 	if (p == '1')
// 	{
// 	}
// }
