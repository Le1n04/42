/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/02/27 16:27:00 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
