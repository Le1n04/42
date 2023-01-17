/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/01/17 14:05:13 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_get_stack(t_stack *m)
{
	int	i;

	i = 0;
}

void	ft_init_vars(t_stack *m, char **argv)
{
	m->args = argv;
	m->b_stack = 0;
	m->a_stack = ft_get_stack(m);
}

int	main(int argc, char **argv)
{
	t_stack	m;

	if (argc < 2)
		ft_printf("%sYou need at least 2 arguments\n", COLOUR_RED);
	else
	{
		ft_init_vars(&m, argv);
	}
}
