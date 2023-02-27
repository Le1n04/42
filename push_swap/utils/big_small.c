/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_small.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/02/27 16:24:02 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_biggest_a(t_stack *m)
{
	int	i;

	i = -1;
	m->biga = -2147483648;
	while (++i < m->size_a)
		if (m->a_stack[i] > m->biga)
			m->biga = m->a_stack[i];
}

void	get_smallest_from_a(t_stack *m, int min)
{
	int	i;

	i = -1;
	m->smalla = 2147483647;
	while (++i < m->size_a)
		if (m->a_stack[i] < m->smalla && m->a_stack[i] > min)
			m->smalla = m->a_stack[i];
}

void	get_smallest_a(t_stack *m)
{
	int	i;

	i = -1;
	m->smalla = 2147483647;
	while (++i < m->size_a)
		if (m->a_stack[i] < m->smalla)
			m->smalla = m->a_stack[i];
}

void	get_smallest_b(t_stack *m)
{
	int	i;

	i = -1;
	m->smallb = 2147483647;
	while (++i < m->size_b)
		if (m->b_stack[i] < m->smallb)
			m->smallb = m->b_stack[i];
}

void	get_biggest_b(t_stack *m)
{
	int	i;

	i = -1;
	m->bigb = -2147483648;
	while (++i < m->size_b)
		if (m->b_stack[i] > m->bigb)
			m->bigb = m->b_stack[i];
}
