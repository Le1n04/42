/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/02/27 16:28:50 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_rra(t_stack *m)
{
	int	i;
	int	*saved;

	i = -1;
	saved = (int *)malloc((m->size_a) * sizeof(int));
	m->tmp = m->a_stack[m->size_a - 1];
	saved[0] = m->tmp;
	while (++i < m->size_a - 1)
		saved[i + 1] = m->a_stack[i];
	free(m->a_stack);
	m->a_stack = saved;
	if (m->printable == 1)
		printf("rra\n");
	m->printable = 1;
	return (m);
}

t_stack	*ft_rrb(t_stack *m)
{
	int	i;
	int	*saved;

	i = -1;
	saved = (int *)malloc((m->size_b) * sizeof(int));
	m->tmp = m->b_stack[m->size_b - 1];
	saved[0] = m->tmp;
	while (++i < m->size_b - 1)
		saved[i + 1] = m->b_stack[i];
	free(m->b_stack);
	m->b_stack = saved;
	if (m->printable == 1)
		printf("rrb\n");
	m->printable = 1;
	return (m);
}

t_stack	*ft_rrr(t_stack *m)
{
	m->printable = 0;
	ft_rra(m);
	m->printable = 0;
	ft_rrb(m);
	return (printf("rrr\n"), m);
}
