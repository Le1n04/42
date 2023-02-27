/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/02/27 16:33:22 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(int *ar1, int *ar2)
{
	int	tmp;

	tmp = *ar1;
	*ar1 = *ar2;
	*ar2 = tmp;
}

t_stack	*remove_from_stack_a(t_stack *m)
{
	int	i;
	int	*saved;

	i = -1;
	saved = (int *)malloc(m->size_a * sizeof(int));
	while (++i < m->size_a)
		saved[i] = m->a_stack[i];
	m->tmp = m->a_stack[0];
	free(m->a_stack);
	m->size_a--;
	m->a_stack = (int *)malloc(m->size_a * sizeof(int));
	i = -1;
	while (++i < m->size_a)
		m->a_stack[i] = saved[i + 1];
	return (free(saved), m);
}

t_stack	*remove_from_stack_b(t_stack *m)
{
	int	i;
	int	*saved;

	i = -1;
	saved = (int *)malloc(m->size_b * sizeof(int));
	while (++i < m->size_b)
		saved[i] = m->b_stack[i];
	m->tmp = m->b_stack[0];
	free(m->b_stack);
	m->size_b--;
	m->b_stack = (int *)malloc(m->size_b * sizeof(int));
	i = -1;
	while (++i < m->size_b)
		m->b_stack[i] = saved[i + 1];
	return (free(saved), m);
}

t_stack	*add_to_stack_a(t_stack *m)
{
	int	i;
	int	*saved;

	i = 0;
	m->size_a++;
	saved = (int *)malloc((m->size_a) * sizeof(int));
	saved[0] = m->tmp;
	while (++i < m->size_a)
		saved[i] = m->a_stack[i - 1];
	free(m->a_stack);
	m->a_stack = saved;
	return (m);
}

t_stack	*add_to_stack_b(t_stack *m)
{
	int	i;
	int	*saved;

	i = 0;
	m->size_b++;
	saved = (int *)malloc((m->size_b) * sizeof(int));
	saved[0] = m->tmp;
	while (++i < m->size_b)
		saved[i] = m->b_stack[i - 1];
	free(m->b_stack);
	m->b_stack = saved;
	return (m);
}
