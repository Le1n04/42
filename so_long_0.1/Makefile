# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#              #
#    Updated: 2022/12/19 16:44:13 by djanssen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c utils/*.c gnl/*.c
OBJ = $(SRC:.c=.o)
RM = rm -f
CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDE = -framework Cocoa -framework OpenGL -framework IOKit
MLX = inc/libmlx42.a
GLFW = inc/libglfw3.a
LIBFT = inc/libft.a
all:            $(NAME)
				$(CC) $(FLAGS) $(SRC) $(NAME) $(LIBFT) $(GLFW) $(MLX) $(INCLUDE) -o so_long
$(NAME):        $(OBJ)
				cd MLX42 && make all
				$(CC) $(FLAGS) -c $(SRC)
				ar rcs $(NAME) $(OBJ)
clean:
				$(RM) $(OBJS)
fclean:         clean
				$(RM) $(NAME) so_long
exe:			all
				@./$(NAME)
re:				fclean $(NAME)
run:
				./so_long