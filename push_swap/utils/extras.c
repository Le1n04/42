/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/02/27 17:23:18 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	main_cooker(t_stack *m)
{
	int	min;

	get_smallest_a(m);
	min = m->smalla;
	while (m->size_a > 3)
	{
		get_smallest_from_a(m, min);
		while (m->a_stack[0] != m->smalla && m->a_stack[0] != min)
			ft_rra(m);
		ft_pb(m);
	}
	three_order(m);
	while (m->size_b)
	{
		get_biggest_b(m);
		while (m->b_stack[0] != m->bigb)
			ft_rb(m);
		ft_pa(m);
	}
}

void	process(t_stack *m, int n)
{
	while (m->ordered < m->universal_size_a)
	{
		get_max_pro(m, n, m->max_ordered);
		push_to_max(m);
		rotate_push(m);
		send_bot(m);
	}
}
