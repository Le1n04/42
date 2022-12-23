/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/23 13:14:20 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* All includes */
# include "inc/MLX42_mac/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include "gnl/get_next_line.h"
# define WIDTH 64
# define HEIGHT 64

/* All structs */
typedef struct s_elements {
	int		c;
	int		p;
	int		e;
	size_t	x;
	size_t	y;
}	t_elements;

typedef struct s_mapdata
{
	mlx_t		*mlx;
	char		*path;
	char		**matrix;
	size_t		x_axis;
	size_t		y_axis;
	int			error;
	int			cc;
	t_elements	elm;
	size_t		player_x;
	size_t		player_y;
	int			game_finished;
	int			moves;
}	t_map;


/* All function prototypes */
int32_t		main(int argc, char **argv);
#endif