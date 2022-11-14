/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:12:30 by djanssen          #+#    #+#             */
/*   Updated: 2022/11/14 19:09:34 by djanssen         ###   ########.fr       */
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

int				ft_printf(char const *format, ...);
int				ft_printchar(int c);
int				ft_printpercentage(void);
int				ft_printstr(char *str);
int				ft_printnbr(int n);
int				ft_printunsignednbr(unsigned int n);
char			*ft_unsigneditoa(unsigned int n);
int				ft_printpointer(unsigned long long ptr);
#endif