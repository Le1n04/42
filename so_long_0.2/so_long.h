/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/21 18:11:15 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* All includes */
# include "inc/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include "gnl/get_next_line.h"

/* All structs */
typedef struct s_mapdata
{
	char	*path;
	char	**matrix;
	size_t	x_axis;
	size_t	y_axis;
	int		error;
}	t_map;

typedef struct s_elements {
	int	c;
	int	p;
	int	e;
	int	x;
	int	y;
}	t_elements;
/* All function prototypes */
int32_t		main(int argc, char **argv);
#endif