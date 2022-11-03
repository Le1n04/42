/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:18:41 by djanssen          #+#    #+#             */
/*   Updated: 2022/10/31 12:17:45 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_linex(char *str)
{
	char	*linea;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i])
		i++;
	linea = (char *)malloc((i + 1) * sizeof(char));
	if (!linea)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		linea[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		linea[i++] = '\n';
	linea[i] = '\0';
	return (linea);
}

char	*get_next(char *str)
{
	char	*c;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
		return (free(str), NULL);
	if (str[i])
		i++;
	c = ft_strdup(&str[i]);
	free(str);
	return (c);
}

char	*readjoin(int fd, char *s)
{
	int		read_val;
	char	*buffer;

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
	return (s);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*s[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s[fd] = readjoin(fd, s[fd]);
	line = get_linex(s[fd]);
	s[fd] = get_next(s[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	int		i;
// 	char	*c;

// 	i = 0;
// 	fd = open("1char.txt", O_RDONLY);
// 	while (i < 1000000)
// 	{
// 		c = get_next_line(fd);
// 		printf(">%s<", c);
// 		free(c);
// 		i++;
// 	}
// 	close(fd);
// }
