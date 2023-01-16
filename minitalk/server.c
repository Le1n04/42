/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/01/16 18:22:55 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "inc/ft_printf/src/ft_printf.h"

int	g_loop = 1;

static void	ft_print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: \033[0;32m%d\n\033[0;37m", pid);
}

void	ft_close_connection(void)
{
	ft_printf("\033[0;33m\nServer closed\n\033[0;37m");
	g_loop = 0;
}

void	ft_handle_sigs(int signum)
{
	static int		bit;
	static size_t	i;

	if (signum == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
	if (signum == SIGINT)
		ft_close_connection();
}

int	main(int argc, char **argv)
{
	argv = NULL;
	if (argc != 1)
	{
		ft_printf("\033[0;31mServer is executed without parameters,");
		ft_printf("\033[0;31m please try again.\n\033[0;37m");
		return (0);
	}
	else
	{
		ft_print_pid();
		while (g_loop)
		{
			signal(SIGUSR1, ft_handle_sigs);
			signal(SIGUSR2, ft_handle_sigs);
			signal(SIGINT, ft_handle_sigs);
		}
	}
	return (1);
}
