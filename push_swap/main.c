/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/01/23 18:15:24 by djanssen         ###   ########.fr       */
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
	return (m);
}

t_stack	*ft_sb(t_stack *m)
{
	if (m->b_stack[1])
		ft_swap(&m->b_stack[0], &m->b_stack[1]);
	return (m);
}

t_stack	*ft_ss(t_stack *m)
{
	ft_sa(m);
	ft_sb(m);
	return (m);
}

t_stack	*remove_from_stack_a(t_stack *m, int num)
{
	int	i;
	int	*saved;
	int	j;

	i = -1;
	j = 0;
	saved = (int *)malloc(m->size_a * sizeof(int));
	while (++i < m->size_a)
		saved[i] = m->a_stack[i];
	m->tmp = m->a_stack[0];
	if (num == 1)
		m->tmp = m->a_stack[m->size_a - 1];
	free(m->a_stack);
	m->size_a--;
	m->a_stack = (int *)malloc(m->size_a * sizeof(int));
	while (--i >= 0)
	{
		m->a_stack[j] = saved[j];
		j++;
	}
	i = -1;
	if (num == 0)
		while (++i < m->size_a)
			m->a_stack[i] = saved[i + 1];
	return (free(saved), m);
}

t_stack	*remove_from_stack_b(t_stack *m, int num)
{
	int	i;
	int	*saved;
	int	j;

	i = -1;
	j = 0;
	saved = (int *)malloc(m->size_b * sizeof(int));
	while (++i < m->size_b)
		saved[i] = m->b_stack[i];
	m->tmp = m->b_stack[0];
	if (num == 1)
		m->tmp = m->b_stack[m->size_b - 1];
	free(m->b_stack);
	m->size_b--;
	m->b_stack = (int *)malloc(m->size_b * sizeof(int));
	while (--i >= 0)
	{
		m->b_stack[j] = saved[j];
		j++;
	}
	i = -1;
	if (num == 0)
		while (++i < m->size_b)
			m->b_stack[i] = saved[i + 1];
	return (free(saved), m);
}

t_stack *add_to_stack_a(t_stack *m)
{
	int	i;
	int	*saved;

	i = 0;
	saved = (int *)malloc((m->size_a + 1) * sizeof(int));
	saved[0] = m->tmp;
	while (++i < m->size_a)
		saved[i] = m->a_stack[i - 1];
	free(m->a_stack);
	m->size_a++;
	m->a_stack = (int *)malloc(m->size_a * sizeof(int));
	i = -1;
	while (++i < m->size_a)
		m->a_stack[i] = saved[i];
	return (free(saved), m);
}

t_stack *add_to_stack_b(t_stack *m)
{
	int	i;
	int	*saved;

	i = 0;
	saved = (int *)malloc((m->size_b + 1) * sizeof(int));
	saved[0] = m->tmp;
	while (++i < m->size_b)
		saved[i] = m->b_stack[i - 1];
	free(m->b_stack);
	m->size_b++;
	m->b_stack = (int *)malloc(m->size_b * sizeof(int));
	i = -1;
	while (++i < m->size_b)
		m->b_stack[i] = saved[i];
	return (free(saved), m);
}

t_stack *ft_pb(t_stack *m)
{
	remove_from_stack_a(m, 0);
	add_to_stack_b(m);
	return (ft_printf("pb\n"), m);
}

t_stack *ft_pa(t_stack *m)
{
	remove_from_stack_b(m, 0);
	add_to_stack_a(m);
	return (ft_printf("pa\n"), m);
}

int	*ft_get_a_stack(t_stack *m)
{
	int	*tmp;
	int	i;

	i = -1;
	tmp = (int *)malloc(m->size_a * sizeof(int));
	while (m->args[++i])
	{
		tmp[i] = ft_atoi(m->args[i]);
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
}

// void	showleaks(void)
// {
// 	system("leaks -q push_swap");
// }

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

int	main(int argc, char **argv)
{
	t_stack	m;
	int		i;

	i = -1;
	if (argc < 2)
		return (ft_printf("%sYou need at least 2 arguments\n", COLOUR_RED), 1);
	else
	{
		ft_init_vars(&m, argc, argv);
		printcheck(&m);
		ft_pb(&m);
		printcheck(&m);
		ft_pb(&m);
		printcheck(&m);
	}
	return (0);
}
