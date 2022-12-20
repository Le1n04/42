/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/19 17:42:15 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* All includes */
# include "inc/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include "gnl/get_next_line.h"
# define WIDTH 640
# define HEIGHT 640

/* All structs */

typedef struct s_vars {
	void			*mlx;
	void			*img;
	void			*win;
	int				win_w;
	int				win_h;
	char			**map;
}	t_vars;

/* All function prototypes */
int32_t		main(int argc, char **argv);
void		keyhook2(mlx_key_data_t keydata, void *param);
int			get_height(char **map);
char		**get_map(char *fmap);
char		**ft_split(const char *str, char c);
void		put_image_to_map(char p, int x1, int y1, t_vars **v);
void		put_image(t_vars ***v, int x, int y, char *img);

#endif