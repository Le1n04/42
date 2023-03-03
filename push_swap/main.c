/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/02/28 14:51:44 by djanssen         ###   ########.fr       */
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
	int		error;

	if (argc < 2)
		return (write(1, COLOUR_RED"You need at least 2 arguments\n", 37), 1);
	error = alpha_checker(argc, argv);
	if (argc == 2)
		return (0);
	if (argc > 2 && error == 0)
	{
		ft_init_vars(&m, argc, argv);
		new_srp(&m);
	}
	if (error > 0)
		write(1, "Error\n", 6);
	return (0);
}
