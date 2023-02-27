/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/02/27 17:23:32 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	three_order(t_stack *m)
{
	if (m->a_stack[0] < m->a_stack[1] && m->a_stack[1] > m->a_stack[2]
		&& m->a_stack[0] < m->a_stack[2])
	{
		ft_rra(m);
		ft_sa(m);
	}
	else if (m->a_stack[0] > m->a_stack[1] && m->a_stack[1] < m->a_stack[2]
		&& m->a_stack[0] < m->a_stack[2])
		ft_sa(m);
	else if (m->a_stack[0] < m->a_stack[1] && m->a_stack[1] > m->a_stack[2]
		&& m->a_stack[0] > m->a_stack[2])
		ft_rra(m);
	else if (m->a_stack[0] > m->a_stack[1] && m->a_stack[1] < m->a_stack[2]
		&& m->a_stack[0] > m->a_stack[2])
		ft_ra(m);
	else if (m->a_stack[0] > m->a_stack[1] && m->a_stack[1] > m->a_stack[2]
		&& m->a_stack[0] > m->a_stack[2])
	{
		ft_sa(m);
		ft_rra(m);
	}
}

void	get_max_pro(t_stack *m, int num, int min)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	get_smallest_from_a(m, min);
	j = 1;
	count = 0;
	while (++i < m->size_a && count < num)
	{
		if (m->a_stack[i] == m->smalla + j)
		{
			count++;
			m->max_pro = m->a_stack[i];
			j++;
			i = -1;
		}
		if (m->max_pro == m->universal_big)
			m->max_pro++;
	}
}

void	push_to_max(t_stack *m)
{
	int	i;
	int	tmp;
	int	x;

	tmp = m->size_a;
	i = -1;
	get_smallest_a(m);
	while ((++i < tmp && m->num_count <= tmp / 2) || (m->num_count > tmp / 2
			&& m->a_stack[0] != m->smalla))
	{
		m->rot = 1;
		if (m->a_stack[0] < m->max_pro && m->a_stack[0] > m->max_ordered)
		{
			ft_pb(m);
			m->rot = 0;
		}
		if (m->rot == 1 && check_if_ordered(m))
			ft_ra(m);
	}
	if (m->num_count > tmp / 2)
	{
		x = tmp - m->num_count - m->size_b;
		while (x--)
			ft_rra(m);
	}
}

void	send_bot(t_stack *m)
{
	int	i;

	i = -1;
	while (++i < m->fake_ordered)
		ft_ra(m);
}

void	new_srp(t_stack *m)
{
	int	n;

	if (check_if_ordered(m))
	{
		n = 27;
		if (m->size_a > 200)
			n = 63;
		init_srp(m);
		if (m->size_a == 2)
			if (check_if_ordered(m))
				ft_ra(m);
		if (m->size_a == 3)
			three_order(m);
		if (m->size_a > 3 && m->size_a < 10)
			main_cooker(m);
		if (m->size_a >= 10)
			process(m, n);
	}
}
