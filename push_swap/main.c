/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/02/20 13:35:59 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *ar1, int *ar2)
{
	int	tmp;

	tmp = *ar1;
	*ar1 = *ar2;
	*ar2 = tmp;
}

t_stack	*ft_sa(t_stack *m)
{
	if (m->a_stack[1])
		ft_swap(&m->a_stack[0], &m->a_stack[1]);
	return (printf("sa\n"), m);
}

t_stack	*ft_sb(t_stack *m)
{
	if (m->b_stack[1])
		ft_swap(&m->b_stack[0], &m->b_stack[1]);
	return (printf("sa\n"), m);
}

t_stack	*ft_ss(t_stack *m)
{
	ft_sa(m);
	ft_sb(m);
	return (m);
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

t_stack	*ft_pb(t_stack *m)
{
	remove_from_stack_a(m);
	add_to_stack_b(m);
	return (printf("pb\n"), m);
}

t_stack	*ft_pa(t_stack *m)
{
	remove_from_stack_b(m);
	add_to_stack_a(m);
	return (printf("pa\n"), m);
}

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
		printf("ra\n");
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
		printf("rb\n");
	m->printable = 1;
	return (m);
}

t_stack	*ft_rr(t_stack *m)
{
	m->printable = 0;
	ft_ra(m);
	m->printable = 0;
	ft_rb(m);
	return (printf("rr\n"), m);
}

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
	m->ordered = 0;
	m->done = 0;
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

void	get_biggest_a(t_stack *m)
{
	int	i;

	i = -1;
	m->biga = -2147483648;
	while (++i < m->size_a)
		if (m->a_stack[i] > m->biga)
			m->biga = m->a_stack[i];
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

void	get_smallest_from_a(t_stack *m, int min)
{
	int	i;

	i = -1;
	m->smalla = 2147483647;
	while (++i < m->size_a)
		if (m->a_stack[i] < m->smalla && m->a_stack[i] > min)
			m->smalla = m->a_stack[i];
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
	}
}

void	push_to_max(t_stack *m)
{
	int	i;
	int	tmp;

	tmp = m->size_a;
	i = -1;
	get_biggest_a(m);
	while (++i < tmp)
	{
		m->rot = 1;
		if (m->a_stack[0] < m->max_pro && m->a_stack[0] > m->ordered)
		{
			ft_pb(m);
			m->rot = 0;
		}
		if (m->rot == 1)
			ft_ra(m);
	}
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

void	rotate_push(t_stack *m)
{
	int	i;

	m->fake_ordered = 0;
	while (m->size_b)
	{
		i = -1;
		get_biggest_b(m);
		while (++i < m->size_b)
			if (m->b_stack[i] == m->bigb)
				break ;
		if (i <= (m->size_b / 2))
			while (m->bigb != m->b_stack[0])
				ft_rb(m);
		else
			while (m->bigb != m->b_stack[0])
				ft_rrb(m);
		ft_pa(m);
		m->fake_ordered++;
		m->ordered++;
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
	int	i;

	i = -1;
	m->count = 0;
	get_smallest_a(m);
	get_biggest_a(m);
	m->max_macro = m->size_a / 20;
	m->ordered = m->smalla - 1;
	while (m->ordered != m->biga - 1)
	{
		get_max_pro(m, 20, m->ordered);
		push_to_max(m);
		rotate_push(m);
		if (m->count < m->max_macro)
			send_bot(m);
		m->count++;
	}
	if (m->a_stack[0] == m->biga)
		ft_ra(m);
}

// void	showleaks(void)
// {
// 	system("leaks -q push_swap");
// }

int	main(int argc, char **argv)
{
	t_stack	m;

	if (argc < 2)
		return (printf("%sYou need at least 2 arguments\n", COLOUR_RED), 1);
	else if (argc == 2)
		return (0);
	else
	{
		ft_init_vars(&m, argc, argv);
		new_srp(&m);
	}
	return (0);
}
