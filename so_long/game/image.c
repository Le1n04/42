/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/12 20:07:04 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putimg(t_vars ***v, int x, int y, char *img)
{
	(**v)->img = mlx_texture_to_image((**v)->mlx, img);
	mlx_image_to_window((**v)->mlx, (**v)->img, x, y);
}

void	img2map(char p, int x1, int y1, t_vars **v)
{
	if (p == '1')
		putimg(&v, x1, y1, "../pngs/:o.png");
}
