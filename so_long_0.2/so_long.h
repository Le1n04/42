/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/28 17:07:12 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* All includes */
# include "gnl/get_next_line.h"
# include "inc/MLX42_mac/include/MLX42/MLX42.h"
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define WIDTH 64
# define HEIGHT 64

/* All structs */
typedef struct s_elements
{
	int			c;
	int			p;
	int			e;
	size_t		x;
	size_t		y;
}				t_elements;

// typedef enum mlx_images
// {
// 	wall,
// 	tile,
// 	player,
// 	ext,
// 	coin,
// 	IMG_COUNT,
// }				t_images;

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
	// mlx_image_t	*img[IMG_COUNT];
	// xpm_t		*xpm[IMG_COUNT];
}				t_map;

/* All function prototypes */
int32_t			main(int argc, char **argv);
void			ft_check_elements(t_map *map);
void			ft_check_lines(char *tmp, size_t current, t_map *fmap);
int				ft_print_error(int error);
void			ft_where_is_player(t_map *fmap);
int				ft_check_ones(char *tmp);
void			keyhook1(mlx_key_data_t keydata, void *param);
void			init_vars(t_map *fmap, char *input);
size_t			get_height(char *input);
void			ft_print_map(t_map *fmap);
t_map			read_map(char *input);
void			moveup(t_map *map);
void			movedown(t_map *map);
void			moveright(t_map *map);
void			moveleft(t_map *map);
void			ft_move(t_map *map, int k);
// int				ft_loadimg(xpm_t **xpm);
// int				ft_texturetoimg(t_map *m, xpm_t **xpm, mlx_image_t **img);
// int				ft_init_graphics(t_map *map);
#endif