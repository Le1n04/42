/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/12 20:07:33 by djanssen         ###   ########.fr       */
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
# define WIDTH 1680
# define HEIGHT 1050

/* All structs */
typedef struct s_vars
{
	void	*mlx;
	void	*img;
	void	*window;
	char	**map;
	int		win_w;
	int		win_h;
	int		movement;
}	t_vars;

/* All function prototypes */
void		key_hooks(void *param);

char		**get_map(char *map_file);

char		**ft_split(const char *str, char c);

int32_t		main(int argc, char **argv);

void		img2map(char p, int x1, int y1, t_vars **v);

#endif