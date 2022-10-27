/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:18:41 by djanssen          #+#    #+#             */
/*   Updated: 2022/10/27 13:53:53 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	char	*line;
	int		i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i - 1] != '\n' && str[i])
		i++;
	line = malloc(sizeof(char) * (i));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (str[i - 1] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next(char *str)
{
	char	*s;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
		return (free(str), NULL);
	if (str[i])
		i++;
	s = malloc(sizeof(char) * ft_strlen(str + i) + 1);
	if (s == NULL)
		return (NULL);
	j = 0;
	while (str[i])
		s[j++] = str[i++];
	s[j] = '\0';
	free(str);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*s = NULL;
	int			read_val;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_val = 1;
	while ((ft_strchr(s, '\n') == NULL) && read_val)
	{
		read_val = read(fd, buffer, BUFFER_SIZE);
		if (read_val <= 0)
			break ;
		buffer[read_val] = '\0';
		s = ft_strjoin(s, buffer);
	}
	free(buffer);
	line = get_line(s);
	s = get_next(s);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	int		i;
// 	char	*c;
//
// 	i = 0;
// 	fd = open("poya.txt", O_RDONLY);
// 	while (i < 2)
// 	{
// 		c = get_next_line(fd);
// 		printf(">%s<", c);
// 		free(c);
// 		i++;
// 	}
// 	close(fd);
// }

	// if (str[i] == '\n' && str[i + 1] != 0)
	// {
	// 	c = str;
	// 	str = ft_strdup(&str[i + 1]);
	// 	free(c);
	// }
	// else
	// {
	// 	free(str);
	// 	str = NULL;
	// 	return (str);
	// }

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*s = NULL;
	int			read_val;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_val = 1;
	while ((ft_strchr(s, '\n') == NULL) && read_val)
	{
		read_val = read(fd, buffer, BUFFER_SIZE);
		if (read_val <= 0)
			break ;
		buffer[read_val] = '\0';
		s = ft_strjoin(s, buffer);
	}
	free(buffer);
	line = get_linex(s);
	s = get_next(s);
	return (line);
}
