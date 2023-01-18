/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/01/18 16:36:58 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_sa(t_stack *m)
{
	int	tmp;

	tmp = m->a_stack[0];
	m->a_stack[0] = m->a_stack[1];
	m->a_stack[1] = tmp;
	return (m);
}

t_stack	*ft_sb(t_stack *m)
{
	int	tmp;

	tmp = m->b_stack[0];
	m->b_stack[0] = m->b_stack[1];
	m->b_stack[1] = tmp;
	return (m);
}

t_stack	*ft_ss(t_stack *m)
{
	ft_sa(m);
	ft_sb(m);
	return (m);
}

// t_stack *ft_pa(t_stack *m)
// {
// 	int	tmp;

// 	tmp = m->b_stack[0];
// 	m->a_stack[0] = m->b_stack[0];
// }

int	*ft_get_a_stack(t_stack *m)
{
	int	*tmp;
	int	i;

	i = -1;
	tmp = (int *)malloc(m->size * sizeof(int));
	while (m->args[++i])
	{
		tmp[i] = ft_atoi(m->args[i]);
	}
	return (tmp);
}

int	*ft_get_b_stack(t_stack *m)
{
	int	*tmp;

	tmp = (int *)malloc(m->size * sizeof(int));
	return (tmp);
}

void	ft_init_vars(t_stack *m, int argc, char **argv)
{
	m->args = &argv[1];
	m->b_stack = ft_get_b_stack(m);
	m->a_stack = ft_get_a_stack(m);
	m->size = argc - 1;
}

// void	showleaks(void)
// {
// 	system("leaks -q push_swap");
// }

void printcheck(t_stack *m)
{
	int	i;

	i = -1;
	printf("\nPre-Move:\n");
	while (m->a_stack[++i])
		printf("%d %d\n", m->a_stack[i], m->b_stack[i]);
	printf("- -\n");
	printf("a b\n");
	ft_ss(m);
	i = -1;
	printf("\nPost-Move:\n");
	while (m->a_stack[++i])
		printf("%d %d\n", m->a_stack[i], m->b_stack[i]);
	printf("- -\n");
	printf("a b\n");
}

int	main(int argc, char **argv)
{
	t_stack	m;
	int		i;

	i = -1;
	if (argc < 2)
		return (ft_printf("%sYou need at least 2 arguments\n", COLOUR_RED), EXIT_FAILURE);
	else
	{
		ft_init_vars(&m, argc, argv);
		printcheck(&m);
	}
	return (EXIT_SUCCESS);
}
