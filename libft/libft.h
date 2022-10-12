/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:12:30 by djanssen          #+#    #+#             */
/*   Updated: 2022/10/10 13:50:08 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
int		ft_isalpha(int n);
int		ft_isdigit(int n);
int		ft_isalnum(int n);
int		ft_isascii(int n);
int		ft_isprint(int n);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t nb);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strdup(const char *s1);
// // ADDITIONAL
// char *ft_substr(char const *s, unsigned int start, size_t len);
// char *ft_strjoin(char const *s1, char const *s2);
// char *ft_strtrim(const char *s1, char const *set);
// char **ft_split(char const *s, char c);
// char *ft_itoa(int n);
// char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
// void ft_striteri(char *s, void (*f)(unsigned int, char *));
// void ft_putchar_fd(char c, int fd);
// void ft_putstr_fd(char *s, int fd);
// void ft_putendl_fd(char *s, int fd);
// void ft_putnbr_fd(int n, int fd);
// // BONUS
// t_list *ft_lstnew(void *content);
// void ft_lstadd_front(t_list **lst, t_list *new);
// int ft_lstsize(t_list *lst);
// t_list *ft_lstlast(t_list *lst);
// void ft_lstadd_back(t_list **lst, t_list *new);
// void ft_lstdelone(t_list *lst, void (*del)(void *));
// void ft_lstclear(t_list **lst, void (*del)(void *));
// void ft_lstiter(t_list *lst, void (*f)(void *));
// t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
// */
#endif