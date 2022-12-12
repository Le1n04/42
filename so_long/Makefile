# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:03:12 by djanssen          #+#    #+#              #
#    Updated: 2022/12/12 20:08:11 by djanssen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = game/ft_split.c game/get_map.c game/keyhooks.c gnl/get_next_line.c gnl/get_next_line_utils.c game/image.c
OBJ = $(SRC:.c=.o)
RM = rm -f
CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDE = -framework Cocoa -framework OpenGL -framework IOKit
MLX = inc/libmlx42.a
GLFW = inc/libglfw3.a
LIBFT = inc/libft.a
all:            $(NAME)
				$(CC) $(FLAGS) main.c $(SRC) $(NAME) $(LIBFT) $(GLFW) $(MLX) $(INCLUDE) -o so_long
$(NAME):        $(OBJ)
				cd libft && make all
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