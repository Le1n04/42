/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/02/28 12:28:37 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_ra(t_stack *m)
{
	int	i;
	int	*saved;

	i = -1;
	saved = (int *)malloc((m->size_a) * sizeof(int));
	m->tmp = m->a_stack[0];
	while (++i < m->size_a)
		saved[i] = m->a_stack[i + 1];
	free(m->a_stack);
	saved[m->size_a - 1] = m->tmp;
	m->a_stack = saved;
	if (m->printable == 1)
		write(1, "ra\n", 3);
	m->printable = 1;
	return (m);
}

t_stack	*ft_rb(t_stack *m)
{
	int	i;
	int	*saved;

	i = -1;
	saved = (int *)malloc((m->size_b) * sizeof(int));
	m->tmp = m->b_stack[0];
	while (++i < m->size_b)
		saved[i] = m->b_stack[i + 1];
	free(m->b_stack);
	saved[m->size_b - 1] = m->tmp;
	m->b_stack = saved;
	if (m->printable == 1)
		write(1, "rb\n", 3);
	m->printable = 1;
	return (m);
}

t_stack	*ft_rr(t_stack *m)
{
	m->printable = 0;
	ft_ra(m);
	m->printable = 0;
	ft_rb(m);
	return (write(1, "rr\n", 3), m);
}
