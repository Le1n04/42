/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/02/28 14:49:17 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	cooking_loop(t_stack *m)
{
	int	min;
	int	count;
	int	i;

	count = 0;
	get_smallest_a(m);
	min = m->smalla;
	get_smallest_from_a(m, min);
	while (count < 2)
	{
		i = 0;
		while (m->a_stack[i] != m->smalla && m->a_stack[i] != min)
			i++;
		if (i <= m->size_a / 2)
			while (m->a_stack[0] != m->smalla && m->a_stack[0] != min)
				ft_ra(m);
		else
			while (m->a_stack[0] != m->smalla && m->a_stack[0] != min)
				ft_rra(m);
		count++;
		if (m->size_a > 3)
			ft_pb(m);
	}
}

void	main_cooker(t_stack *m)
{
	while (m->size_a > 3)
		cooking_loop(m);
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

int	alpha_checker(int argc, char **argv)
{
	int	i;
	int	j;
	int	error;

	error = 0;
	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			if ((argv[i][j] >= 'a' && argv[i][j] <= 'z') ||
				(argv[i][j] >= 'A' && argv[i][j] <= 'Z'))
				error++;
	}
	error += dup_checker(argc, argv, error);
	return (error);
}

int	dup_checker(int argc, char **argv, int error)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				error++;
			j++;
		}
		i++;
	}
	return (error);
}
