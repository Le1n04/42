# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#              #
#    Updated: 2023/01/16 15:59:03 by djanssen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS=ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c \
	ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c ft_strrchr.c ft_strncmp.c\
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_memchr.c ft_atoi.c ft_memcmp.c \
	ft_strnstr.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \


OBJS=$(SRCS:.c=.o)

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJS =$(BONUS:.c=.o)
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.
$(NAME):
	@echo Compiling libft...
	@gcc -c $(CFLAGS) $(SRCS)
	@echo Libft compiled!
	@ar rcs $(NAME) $(OBJS)
bonus: ${OBJS} ${BONUS_OBJS}
	ar rs ${NAME} ${OBJS} ${BONUS_OBJS}
all: $(NAME)
clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
fclean: clean
	@echo Cleaning...
	@$(RM) $(NAME)
	@echo Clean!
re: fclean all
.PHONY: all clean fclean re bonus