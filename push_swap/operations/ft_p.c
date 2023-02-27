/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/02/27 16:21:54 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	m->num_count++;
	return (printf("pa\n"), m);
}
