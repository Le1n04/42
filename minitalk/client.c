/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#             */
/*   Updated: 2023/01/16 18:22:28 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "inc/ft_printf/src/ft_printf.h"

/**
 * @param usleep This function will wait until a signal is delivered (or 100ms)
 * @param bit Current bit count (max 8).
 * @param pid Process number passed to integer.
 * @param msg argv[2] - The message to print in server.
 */
void	ft_msg_sender(int pid, char msg)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((msg & (0x01 << bit)))
			kill (pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

/*
Need to pass argv[1] to integer to use kill in 'ft_msg_sender' function.
*/
int	main(int argc, char **argv)
{
	int		pid;
	size_t	i;

	if (argc < 3)
	{
		ft_printf("\033[0;31mPlease use: ./client <PID> <MESSAGE>");
		return (0);
	}
	i = -1;
	pid = ft_atoi(argv[1]);
	while (argv[2][++i])
		ft_msg_sender(pid, argv[2][i]);
	return (1);
}
