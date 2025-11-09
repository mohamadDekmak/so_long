/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:11:20 by mdekmak           #+#    #+#             */
/*   Updated: 2025/11/09 14:11:20 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*get_map(char *path)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->arr = read_lines(path, &map->height);
	if (!map->arr)
		return (NULL);
	if (!is_rectangular(map))
		return (ft_putstr_fd("Error\nNot rectangular\n", 1),
			free_map(map), NULL);
	if (!check_walls(map))
		return (ft_putstr_fd("Error\nNot surrounded by walls\n", 1),
			free_map(map), NULL);
	if (!check_characters(map))
		return (ft_putstr_fd("Error\nInvalid characters\n", 1),
			free_map(map), NULL);
	return (map);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map->arr && map->arr[i])
		free(map->arr[i++]);
	free(map->arr);
	free(map);
}

int	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	return (len > 4 && ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

void	flood_fill(char **map_copy, t_point p, int width, int height)
{
	if (p.x < 0 || p.y < 0 || p.x >= width || p.y >= height)
		return ;
	if (map_copy[p.y][p.x] == '1' || map_copy[p.y][p.x] == 'V'
		|| map_copy[p.y][p.x] == 'E')
		return ;
	map_copy[p.y][p.x] = 'V';
	flood_fill(map_copy, (t_point){p.x + 1, p.y}, width, height);
	flood_fill(map_copy, (t_point){p.x - 1, p.y}, width, height);
	flood_fill(map_copy, (t_point){p.x, p.y + 1}, width, height);
	flood_fill(map_copy, (t_point){p.x, p.y - 1}, width, height);
}

char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->arr[i]);
		if (!copy[i])
		{
			i--;
			while (i >= 0)
			{
				free(copy[i]);
				i--;
			}
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
