/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanssen <djanssen@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:48:59 by djanssen          #+#    #+#             */
/*   Updated: 2022/12/19 16:31:02 by djanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

static void	errormsg(void)
{
	perror("Guatemala");
	exit(1);
}

char	**get_map(char *fmap)
{
	char	*line;
	char	*lines;
	int		fd;

	line = "";
	lines = ft_strdup("");
	fd = open(fmap, O_RDONLY);
	if (fd < 0)
		errormsg();
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		lines = ft_strjoin(lines, line);
		free (line);
	}
	free(line);
	close(fd);
	if (lines[0] == '\0')
		errormsg();
	return (ft_split(lines, '\n'));
}
