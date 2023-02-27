# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#              #
#    Updated: 2023/02/27 16:27:42 by djanssen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = *.c operations/*.c utils/*.c
OBJ = $(SRC:.c=.o)
RM = rm -f
CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBFT = ft_printf/libftprintf.a
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_GREY=\033[0;37m
all:            $(NAME) 
				@echo "$(COLOUR_BLUE)Compiling...$(COLOUR_GREY)"
				@cd ft_printf && make
				@$(CC) $(FLAGS) $(SRC) $(NAME) $(LIBFT) -o push_swap
				@clear
				@echo "$(COLOUR_GREEN)Success!$(COLOUR_GREY)"
$(NAME):        $(OBJ)
				@$(CC) $(FLAGS) -c $(SRC)
				@ar rcs $(NAME) $(OBJ)
clean:
				@$(RM) $(OBJS)
fclean:         clean
				@echo "$(COLOUR_BLUE)Cleaning...$(COLOUR_GREY)"
				@$(RM) $(NAME) push_swap
				@cd ft_printf && make fclean
				@clear
				@echo "$(COLOUR_GREEN)Clean!$(COLOUR_GREY)"