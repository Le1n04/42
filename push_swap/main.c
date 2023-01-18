/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/01/18 18:36:11 by djanssen         ###   ########.fr       */
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

t_stack	*ft_pb(t_stack *m)
{
	int	i;
	int	tmp;

	if (m->a_stack[0])
	{
		i = -1;
		tmp = m->a_stack[0];
		while (++i < m->size_a)
			ft_swap(&m->a_stack[i], &m->a_stack[i + 1]);
		m->size_a--;
		if (!m->b_stack[0])
		{
			m->b_stack[0] = tmp;
			m->size_b++;
		}
		else if (m->b_stack[0])
		{
			i = -1;
			while (++i <= m->size_b)
			{
				m->b_stack[i + 1] = m->b_stack[i];
				m->b_stack[0] = tmp;
			}
		}
	}
	return (m);
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

	tmp = (int *)malloc(m->size_b * sizeof(int));
	return (tmp);
}

void	ft_init_vars(t_stack *m, int argc, char **argv)
{
	m->args = &argv[1];
	m->b_stack = ft_get_b_stack(m);
	m->a_stack = ft_get_a_stack(m);
	m->size_a = argc - 1;
	m->size_b = 0;
}

// void	showleaks(void)
// {
// 	system("leaks -q push_swap");
// }

void printcheck(t_stack *m)
{
	int	i;

	i = 0;
	printf("\nMove:\n");
	while (m->a_stack[i] != '\0')
	{	
		printf("%d %d\n", m->a_stack[i], m->b_stack[i]);
		i++;
	}
	printf("- -\n");
	printf("a b\n");
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
		ft_pb(&m);
		printcheck(&m);
	}
	return (0);
}
