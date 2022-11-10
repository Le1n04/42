/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:12:30 by djanssen          #+#    #+#             */
/*   Updated: 2022/11/08 14:02:35 by djanssen         ###   ########.fr       */
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
# include "../libft/libft.h"

int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_printunsigned(unsigned int n);
int		ft_printpercentage(void);
int		ft_printhex(int h, const char format);
void	ft_get_hex(int n, const char format);
char	*ft_itoax(unsigned int n);
int		ft_printf(char const *format, ...);
#endif