/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#             */
/*   Updated: 2023/02/20 14:02:59 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define COLOUR_GREEN "\033[0;32m"
# define COLOUR_RED "\033[0;31m"
# define COLOUR_BLUE "\033[0;34m"
# define COLOUR_GREY "\033[0;37m"
/* All includes */
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "ft_printf/src/ft_printf.h"

typedef struct s_stack
{
	int		*a_stack;
	int		*b_stack;
	char	**args;
	int		size_a;
	int		size_b;
	int		tmp;
	int		smalla;
	int		smallb;
	int		biga;
	int		universal_big;
	int		printable;
	int		rot;
	int		max_pro;
	int		bigb;
	int		ordered;
	int		fake_ordered;
	int		done;
	int		max_macro;
	int		count;
	int		half;
}	t_stack;

#endif