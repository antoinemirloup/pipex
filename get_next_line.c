/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:55:51 by amirloup          #+#    #+#             */
/*   Updated: 2024/01/30 13:13:03 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*ft_line(char *line)
{
	int		i;
	char	*new_line;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	new_line = malloc((i + 2) * sizeof(char));
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	free(line);
	return (new_line);
}

static void	ft_sort(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	ft_memmove(buffer, buffer + i, (BUFFER_SIZE - i));
	ft_bzero(&buffer[BUFFER_SIZE - i], i);
}

static char	*ft_read(int fd, char *line, char *buffer, int cursor)
{
	while (cursor != 0 && !(ft_strchr(buffer, '\n')))
	{
		cursor = read(fd, buffer, BUFFER_SIZE);
		if (cursor == -1)
		{
			ft_bzero(buffer, BUFFER_SIZE);
			free(line);
			return (NULL);
		}
		buffer[cursor] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			cursor;
	static char	buffer[BUFFER_SIZE + 1];

	cursor = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (buffer[0] != '\0')
		line = ft_strjoin(line, buffer);
	line = ft_read(fd, line, buffer, cursor);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	line = ft_line(line);
	ft_sort(buffer);
	return (line);
}
