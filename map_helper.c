/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:08:47 by mdekmak           #+#    #+#             */
/*   Updated: 2025/11/09 14:08:47 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->arr[0][i] != '1' || map->arr[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->arr[i][0] != '1' || map->arr[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_characters_helper(char c, int *co, int *p, int *e)
{
	if (c == 'C')
		(*co)++;
	else if (c == 'P')
		(*p)++;
	else if (c == 'E')
		(*e)++;
	else if (c != '0' && c != '1')
		return (0);
	return (1);
}

void	init_map_counts(t_map *map)
{
	map->collectibles = 0;
	map->players = 0;
	map->exits = 0;
}

int	process_char(t_map *map, int x, int y)
{
	char	c;

	c = map->arr[y][x];
	if (c == 'P')
	{
		map->player.x = x;
		map->player.y = y;
	}
	if (!check_characters_helper(c, &map->collectibles,
			&map->players, &map->exits))
		return (0);
	return (1);
}

int	check_characters(t_map *map)
{
	int	y;
	int	x;

	init_map_counts(map);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (!process_char(map, x, y))
				return (0);
		}
	}
	if (map->players != 1 || map->exits != 1 || map->collectibles < 1)
		return (0);
	return (1);
}
