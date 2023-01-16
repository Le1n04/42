# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#              #
#    Updated: 2023/01/16 18:35:47 by djanssen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_SERVER = server.c
SRC_CLIENT = client.c
OBJ = $(SRC_SERVER:.c=.o) $(SRC_CLIENT:.c=.o)
RM = rm -f
CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBFT = inc/ft_printf/libftprintf.a
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_GREY=\033[0;37m
all:            $(NAME) 
				@echo "$(COLOUR_BLUE)Compiling...$(COLOUR_GREY)"
				@cd inc/ft_printf && make
				@$(CC) $(FLAGS) $(SRC_SERVER) $(NAME) $(LIBFT) -o server
				@$(CC) $(FLAGS) $(SRC_CLIENT) $(NAME) $(LIBFT) -o client
				@clear
				@echo "$(COLOUR_GREEN)Success!$(COLOUR_GREY)"
$(NAME):        $(OBJ)
				@$(CC) $(FLAGS) -c $(SRC)
				@ar rcs $(NAME) $(OBJ)
clean:
				@$(RM) $(OBJS)
fclean:         clean
				@echo "$(COLOUR_BLUE)Cleaning...$(COLOUR_GREY)"
				@$(RM) $(NAME) server client
				@cd inc/ft_printf && make fclean
				@clear
				@echo "$(COLOUR_GREEN)Clean!$(COLOUR_GREY)"