/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:18:41 by djanssen          #+#    #+#             */
/*   Updated: 2022/10/26 12:45:42 by djanssen         ###   ########.fr       */
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
	if (str[i] == '\n')
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
	c = malloc(sizeof(char) * ft_strlen(str + i) + 1);
	if (c == NULL)
		return (NULL);
	j = 0;
	while (str[i])
		c[j++] = str[i++];
	c[j] = '\0';
	free(str);
	return (c);
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
	line = get_linex(s);
	s = get_next(s);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	int		i;
// 	char	*c;

// 	i = 0;
// 	fd = open("1char.txt", O_RDONLY);
// 	while (i < 10)
// 	{
// 		c = get_next_line(fd);
// 		printf(">%s<", c);
// 		free(c);
// 		i++;
// 	}
// 	close(fd);
// }
