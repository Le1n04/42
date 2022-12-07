# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#              #
#    Updated: 2022/12/05 18:30:53 by djanssen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long.out

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