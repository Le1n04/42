/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/02/28 14:44:02 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_rr(t_stack *m)
{
	while (m->bigb != m->b_stack[0])
	{
		if (m->smallb == m->b_stack[0])
		{
			ft_pa(m);
			if (m->b_stack[1] != m->bigb)
				ft_rr(m);
			else
				ft_ra(m);
			m->rot_count = 1;
			m->ordered++;
			break ;
		}
		ft_rb(m);
	}
}

void	rotate_rrb(t_stack *m)
{
	while (m->bigb != m->b_stack[0])
	{
		if (m->smallb == m->b_stack[0])
		{
			ft_pa(m);
			ft_ra(m);
			m->rot_count = 1;
			m->ordered++;
			break ;
		}
		ft_rrb(m);
	}
}

void	rotate_push(t_stack *m)
{
	int	i;

	m->fake_ordered = 0;
	get_biggest_b(m);
	m->max_ordered = m->bigb;
	while (m->size_b)
	{
		m->rot_count = 0;
		i = -1;
		get_biggest_b(m);
		get_smallest_b(m);
		while (++i < m->size_b)
			if (m->b_stack[i] == m->bigb)
				break ;
		if (i <= (m->size_b / 2))
			rotate_rr(m);
		else
			rotate_rrb(m);
		if (m->rot_count == 0)
		{
			ft_pa(m);
			m->fake_ordered++;
			m->ordered++;
		}
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
