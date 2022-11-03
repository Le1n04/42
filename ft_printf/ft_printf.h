/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:12:30 by djanssen          #+#    #+#             */
/*   Updated: 2022/11/03 13:52:47 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdarg.h>

/**
 * @brief These infos are given by the flags, and we need to stock these infos
 * in a struct in order to print the string correctly.
 * 
 */
typedef struct s_print
{
	va_list	args;
	int		character;
	int		string;
	int		pointer;
	int		decimal;
	int		integer;
	int		unsignd;
	int		hexl;
	int		hexu;
	int		percentage;
}			t_print;

#endif