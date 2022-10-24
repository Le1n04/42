/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:18:41 by djanssen          #+#    #+#             */
/*   Updated: 2022/10/24 18:22:11 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	char	*linea;
	size_t	i;

	if (!*str)
		return (NULL);
	i = 0;
	while (str[i - 1] != '\n' && str[i])
		i++;
	linea = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	while (str[i - 1] != '\n' && str[i])
	{
		linea[i] = str[i];
		i++;
	}
	linea[i] = '\0';
	return (linea);
}

char	*get_next(char *str)
{
	size_t	i;
	char	*c;

	if (!*str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n' && str[i + 1] != 0)
	{
		c = str;
		str = ft_strdup(&str[i + 1]);
		free(c);
	}
	else
	{
		free(str);
		str = NULL;
		return (str);
	}
	str[ft_strlen(str)] = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*str = NULL;
	int			read_value;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_value = 1;
	while ((ft_strchr(str, '\n') == NULL) && read_value)
	{
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value <= 0)
			break ;
		buffer[read_value] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free (buffer);
	line = get_line(str);
	str = get_next(str);
	if (str == NULL && line == NULL)
		return (NULL);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	int		i;
// 	char	*c;

// 	i = 0;
// 	fd = open("poya.txt", O_RDONLY);
// 	while (i < 7)
// 	{
// 		c = get_next_line(fd);
// 		printf(">%s<", c);
// 		free(c);
// 		i++;
// 	}
// 	close(fd);
// }
