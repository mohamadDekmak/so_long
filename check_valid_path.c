/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:10:49 by mdekmak           #+#    #+#             */
/*   Updated: 2025/11/09 14:10:49 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_copy(char **map_copy)
{
	int	i;

	i = 0;
	while (map_copy[i])
		free(map_copy[i++]);
	free(map_copy);
}

int	check_collectibles_reachable(t_map *map, char **map_copy)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->arr[y][x] == 'C' && map_copy[y][x] == 'V')
				count++;
			x++;
		}
		y++;
	}
	return (count == map->collectibles);
}

int	check_exit_neighbors(t_map *map, char **map_copy, int x, int y)
{
	if (y > 0 && map_copy[y - 1][x] == 'V')
		return (1);
	if (y < map->height - 1 && map_copy[y + 1][x] == 'V')
		return (1);
	if (x > 0 && map_copy[y][x - 1] == 'V')
		return (1);
	if (x < map->width - 1 && map_copy[y][x + 1] == 'V')
		return (1);
	return (0);
}

int	check_exit_reachable(t_map *map, char **map_copy)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->arr[y][x] == 'E')
				return (check_exit_neighbors(map, map_copy, x, y));
			x++;
		}
		y++;
	}
	return (0);
}

int	check_valid_path(t_map *map)
{
	char	**map_copy;

	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, map->player, map->width, map->height);
	if (!check_collectibles_reachable(map, map_copy))
	{
		free_map_copy(map_copy);
		return (0);
	}
	if (!check_exit_reachable(map, map_copy))
	{
		free_map_copy(map_copy);
		return (0);
	}
	free_map_copy(map_copy);
	return (1);
}
