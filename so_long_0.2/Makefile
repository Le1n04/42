# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#              #
#    Updated: 2023/01/16 12:32:49 by djanssen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = gnl/*.c *.c src/*/*.c utils/*.c
OBJ = $(SRC:.c=.o)
RM = rm -f
CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDE = -framework Cocoa -framework OpenGL -framework IOKit
MLX = inc/libmlx42.a
GLFW = inc/libglfw3.a
LIBFT = inc/libft.a
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m
all:            $(NAME) 
				@echo "$(COLOUR_BLUE)Compiling...$(COLOUR_END)"
				@$(CC) $(FLAGS) $(SRC) $(NAME) $(LIBFT) $(GLFW) $(MLX) $(INCLUDE) -o so_long
				@echo "$(COLOUR_GREEN)Success!$(COLOUR_END)"
$(NAME):        $(OBJ)
				cd MLX42_mac && make all
				$(CC) $(FLAGS) -c $(SRC)
				ar rcs $(NAME) $(OBJ)
clean:
				@$(RM) $(OBJS)
fclean:         clean
				@echo "$(COLOUR_BLUE)Cleaning...$(COLOUR_END)"
				@$(RM) $(NAME) so_long
				@echo "$(COLOUR_GREEN)Cleaned!$(COLOUR_END)"