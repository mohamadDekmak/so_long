/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:13:14 by mdekmak           #+#    #+#             */
/*   Updated: 2025/11/09 14:13:14 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(int fd)
{
	int		count;
	char	buffer;

	count = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
			count++;
	}
	return (count + 1);
}

void	fill_map_line(char *buffer, char **result, int *len, int *index)
{
	buffer[*len] = '\0';
	result[*index] = ft_strdup(buffer);
	*len = 0;
	(*index)++;
}

void	fill_map(int fd, char **result)
{
	char	buffer[1024];
	int		len;
	int		index;

	len = 0;
	index = 0;
	while (read(fd, buffer + len, 1) > 0)
	{
		if (buffer[len] == '\n')
			fill_map_line(buffer, result, &len, &index);
		else
			len++;
	}
	if (len > 0)
		fill_map_line(buffer, result, &len, &index);
	result[index] = NULL;
}

char	**read_lines(char *path, int *height)
{
	int		fd;
	char	**result;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	*height = count_lines(fd);
	close(fd);
	fd = open(path, O_RDONLY);
	result = malloc(sizeof(char *) * (*height + 1));
	if (!result)
		return (NULL);
	fill_map(fd, result);
	close(fd);
	return (result);
}

int	is_rectangular(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!map->arr[0])
		return (0);
	len = ft_strlen(map->arr[0]);
	while (map->arr[i])
	{
		if ((int)ft_strlen(map->arr[i]) != len)
			return (0);
		i++;
	}
	map->width = len;
	map->height = i;
	return (1);
}
