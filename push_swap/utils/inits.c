/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/02/27 16:35:37 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ft_get_a_stack(t_stack *m)
{
	int	*tmp;
	int	i;

	i = -1;
	tmp = (int *)malloc(m->size_a * sizeof(int));
	while (m->args[++i])
	{
		tmp[i] = atoi(m->args[i]);
	}
	return (tmp);
}

int	*ft_get_b_stack(t_stack *m)
{
	int	*tmp;

	tmp = (int *)malloc(m->size_a * sizeof(int));
	return (tmp);
}

void	ft_init_vars(t_stack *m, int argc, char **argv)
{
	m->args = &argv[1];
	m->size_a = argc - 1;
	m->size_b = 0;
	m->b_stack = ft_get_b_stack(m);
	m->a_stack = ft_get_a_stack(m);
	m->smalla = 0;
	m->biga = -2147483648;
	m->printable = 1;
	m->rot = 1;
	m->num_count = 0;
}

int	check_if_ordered(t_stack *m)
{
	int	i;

	i = 0;
	while (i < m->size_a - 1 && m->a_stack[i] < m->a_stack[i + 1])
		i++;
	if (i == m->size_a - 1)
		return (0);
	return (1);
}

void	init_srp(t_stack *m)
{
	get_smallest_a(m);
	get_biggest_a(m);
	m->universal_big = m->biga;
	m->ordered = 0;
	m->max_ordered = m->smalla - 1;
	m->universal_size_a = m->size_a;
}
