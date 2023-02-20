void	init_alg(t_stack *m)
{
	if (check_if_ordered(m))
	{
		if (m->size_a == 3)
			three_order(m);
		else if (m->size_a < 10)
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

void	srp(t_stack *m)
{
	while (m->size_a > 0)
	{
		if (!check_if_ordered(m))
			break ;
		get_smallest_a(m);
		rotate_to_small_num(m, m->smalla);
		if (!check_if_ordered(m))
			break ;
		ft_pb(m);
	}
}

void	finish_to_a(t_stack *m)
{
	int	i;

	i = -1;
	while (m->size_b)
		ft_pa(m);
	get_smallest_a(m);
	while (++i < m->size_a)
		if (m->a_stack[i] == m->smalla)
			break ;
	if (i <= (m->size_a / 2))
		while (m->smalla != m->a_stack[0])
			ft_ra(m);
	else
		while (m->smalla != m->a_stack[0])
			ft_rra(m);
}

void	rotate_to_small_num(t_stack *m, int num)
{
	int	i;

	i = -1;
	while (++i < m->size_a)
		if (m->a_stack[i] == num)
			break ;
	if (i <= (m->size_a / 2))
	{
		while (num != m->a_stack[0])
		{
			m->rot = 1;
			get_biggest_a(m);
			if (m->biga == m->a_stack[0])
			{
				ft_pb(m);
				if (num != m->a_stack[0])
				{
					ft_rr(m);
					m->rot = 0;
				}
				else
					ft_rb(m);
			}
			if (m->rot == 1)
				ft_ra(m);
		}
	}
	else
	{
		while (num != m->a_stack[0])
		{
			m->rot = 1;
			get_biggest_a(m);
			if (m->biga == m->a_stack[0])
			{
				ft_pb(m);
				if (num != m->a_stack[0])
				{
					ft_rra(m);
					ft_rb(m);
					m->rot = 0;
				}
				else
					ft_rrb(m);
			}
			if (m->rot == 1)
				ft_rra(m);
		}
	}
}