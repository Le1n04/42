/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#             */
/*   Updated: 2023/02/27 17:25:30 by djanssen         ###   ########.fr       */
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
	int		bigb;
	int		universal_big;
	int		printable;
	int		rot;
	int		max_pro;
	int		ordered;
	int		fake_ordered;
	int		universal_size_a;
	int		rot_count;
	int		num_count;
	int		max_ordered;
}	t_stack;

// Operations //
t_stack	*ft_pb(t_stack *m);
t_stack	*ft_pa(t_stack *m);
t_stack	*ft_ra(t_stack *m);
t_stack	*ft_rb(t_stack *m);
t_stack	*ft_rr(t_stack *m);
t_stack	*ft_rra(t_stack *m);
t_stack	*ft_rrb(t_stack *m);
t_stack	*ft_rrr(t_stack *m);
t_stack	*ft_sa(t_stack *m);
t_stack	*ft_sb(t_stack *m);
t_stack	*ft_ss(t_stack *m);

// Operation Utils //

void	ft_swap(int *ar1, int *ar2);
t_stack	*remove_from_stack_a(t_stack *m);
t_stack	*remove_from_stack_b(t_stack *m);
t_stack	*add_to_stack_a(t_stack *m);
t_stack	*add_to_stack_b(t_stack *m);

// Find Big or Small //

void	get_biggest_a(t_stack *m);
void	get_smallest_from_a(t_stack *m, int min);
void	get_smallest_a(t_stack *m);
void	get_smallest_b(t_stack *m);
void	get_biggest_b(t_stack *m);

// Related to Inits //

int		*ft_get_a_stack(t_stack *m);
int		*ft_get_b_stack(t_stack *m);
void	ft_init_vars(t_stack *m, int argc, char **argv);
int		check_if_ordered(t_stack *m);
void	init_srp(t_stack *m);

// Main Functions //

void	three_order(t_stack *m);
void	get_max_pro(t_stack *m, int num, int min);
void	push_to_max(t_stack *m);
void	send_bot(t_stack *m);
void	new_srp(t_stack *m);
void	rotate_push(t_stack *m);
void	rotate_rrb(t_stack *m);
void	rotate_rr(t_stack *m);
void	process(t_stack *m, int n);

// <10 process //

void	main_cooker(t_stack *m);

//  //

#endif