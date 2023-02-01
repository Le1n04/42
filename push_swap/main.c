/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/02/01 18:15:59 by djanssen         ###   ########.fr       */
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

t_stack *add_to_stack_a(t_stack *m)
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

t_stack *add_to_stack_b(t_stack *m)
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

t_stack *ft_pb(t_stack *m)
{
	remove_from_stack_a(m);
	add_to_stack_b(m);
	return (printf("pb\n"), m);
}

t_stack *ft_pa(t_stack *m)
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
	free (m->a_stack);
	saved[m->size_a - 1] = m->tmp;
	m->a_stack = saved;
	return (printf("ra\n"), m);
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
	free (m->b_stack);
	saved[m->size_b - 1] = m->tmp;
	m->b_stack = saved;
	return (printf("rb\n"), m);
}

t_stack	*ft_rr(t_stack *m)
{
	ft_ra(m);
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
		saved [i + 1] = m->a_stack[i];
	free (m->a_stack);
	m->a_stack = saved;
	return (printf("rra\n"), m);
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
		saved [i + 1] = m->b_stack[i];
	free (m->b_stack);
	m->b_stack = saved;
	return (printf("rrb\n"), m);
}

t_stack	*ft_rrr(t_stack *m)
{
	ft_rra(m);
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
	m->biga = 0;
}

void	printcheck(t_stack *m)
{
	int	i;

	printf("\nA:\n");
	i = 0;
	while (i < m->size_a)
	{
		printf("%d\n", m->a_stack[i]);
		i++;
	}
	printf("\nB:\n");
	i = 0;
	while (i < m->size_b)
	{
		printf("%d\n", m->b_stack[i]);
		i++;
	}
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

void	rotate_to_small_num(t_stack *m, int num)
{
	int	i;

	i = -1;
	while (++i < m->size_a)
		if (m->a_stack[i] == num)
			break ;
	if (i <= (m->size_a / 2))
		while (num != m->a_stack[0])
			ft_ra(m);
	else
		while (num != m->a_stack[0])
			ft_rra(m);
}

void	finish_to_a(t_stack *m)
{
	while (m->size_b)
		ft_pa(m);
}

int check_if_ordered(t_stack *m)
{
	int	i;

	i = 0;
	while (i < m->size_a - 1 && m->a_stack[i] < m->a_stack[i + 1])
		i++;
	if (i == m->size_a - 1)
		return (0);
	return (1);
}

void	srp(t_stack *m)
{
	while (m->size_a > 0)
	{
		get_smallest_a(m);
		rotate_to_small_num(m, m->smalla);
		ft_pb(m);
	}
}

void	srp_mod(t_stack *m)
{
	int	max_perc;
	int	i;
	int	tmp;

	get_smallest_a(m);
	max_perc = m->smalla * 0.75;
	i = -1;
	while (++i < m->size_a)
	{
		if (m->a_stack[i] < max_perc)
		{
			tmp = m->a_stack[i];
			rotate_to_small_num(m, tmp);
			ft_pb(m);
		}
	}
}

void	init_alg(t_stack *m)
{
	if (check_if_ordered(m))
	{
		if (m->size_a == 3)
			three_order(m);
		else if (m->size_a == 5)
		{
			three_order(m);
			srp(m);
		}
		else
		{
			srp(m);
			finish_to_a(m);
		}
	}
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
		init_alg(&m);
	}
	return (0);
}

/**
 * Terminar de hacer las funciones modeadas de srp
 * para mandar el 25% de los numeros pequeños a la derecha y ordenarlos ahi y
 * el objetivo es acortar las rotaciones en A para que no tenga que pasar
 * de un extremo al otro todo el rato.
 * 
 */