/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/03/27 18:35:23 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_num(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
	}
	return (0);
}

void	ft_help(void)
{
	write(1, "Here's a quick summary of what you should know about the ", 58);
	write(1, "introduced arguments:\n\n", 23);
	write(1, "You should be using the next syntax: \n\n", 39);
	write(1, COLOUR_GREEN"./philo <A> <B> <C> <D> <E>\n\n", 36);
	write(1, COLOUR_GREY"<A> = Number of philosophers.\n\n", 38);
	write(1, "<B> Time to die.\n\n", 18);
	write(1, "<C> Time to eat.\n\n", 18);
	write(1, "<D> (Optional) Number of times each philosopher must eat.\n\n", 59);
}

void	philo_creator(t_main *m)
{
	m->philo = malloc(sizeof(t_philo) * (m->n_philo));
	if (m->philo == NULL)
		return (0);
}

void	philo_allocator(t_main *m)
{
	
}

int	init_philo(t_main *m, char **argv)
{
	m->n_philo = ft_atoi(argv[1]);
	m->t_to_die = ft_atoi(argv[2]);
	m->t_to_eat = ft_atoi(argv[3]);
	m->t_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		m->n_philo_times_to_eat = ft_atoi(argv[5]);
	return (0);
}

/**
 * @brief 
 * @param argv1 number_of_philosophers
 * @param argv2 time_to_die
 * @param argv3 time_to_eat
 * @param argv4 time_to_sleep
 * @param argv5 [number_of_times_each_philosopher_must_eat]
 */
int	main(int argc, char **argv)
{
	t_main	m;

	if (argc == 2 && argv[1][0] == 'h' && argv[1][1] == 'e'
		&& argv[1][2] == 'l' && argv[1][3] == 'p' && !argv[1][4])
		return (ft_help(), 0);
	if (argc < 5 || argc > 6)
		return (write(2, "Error.\n", 8), 1);
	else
	{
		if (!check_num(argv))
		{
			if (init_philo(&m, argv))
			{
				return (write(1, "Error\n", 6), 1);
			}
		}
		else
			return (write(1, "Error\n", 6), 1);
	}
	return (0);
}
