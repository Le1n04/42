# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#              #
#    Updated: 2022/10/31 12:38:32 by djanssen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRCS=


OBJS=$(SRCS:.c=.o)

BONUS = 

BONUS_OBJS =$(BONUS:.c=.o)
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