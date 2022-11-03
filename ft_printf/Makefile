# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#              #
#    Updated: 2022/11/03 16:35:20 by djanssen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRCS= ft_printf.c ft_printf_utils.c


OBJS=$(SRCS:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.
$(NAME):
	gcc -c $(CFLAGS) $(SRCS)
	ar rcs $(NAME) $(OBJS)
bonus: ${OBJS} ${BONUS_OBJS}
	ar rs ${NAME} ${OBJS} ${BONUS_OBJS}
all: $(NAME)
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re bonus