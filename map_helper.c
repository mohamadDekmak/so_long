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

void fill_result(int fd, char	**result)
{
	char buffer[1024];
    int len;
    int index;

	len = 0;
	index = 0;
    while (read(fd, buffer + len, 1) > 0)
    {
        if (buffer[len] == '\n')
        {
            buffer[len] = '\0';
            result[index] = ft_strdup(buffer);
            len = 0;
            index++;
        }
        else
            len++;
    }
    if (len > 0)
    {
        buffer[len] = '\0';
        result[index++] = ft_strdup(buffer);
    }
	result[index] = NULL;
}

char	**read_lines(char *path, int *height)
{
	int	fd;
	char	**result;

	fd = open(path, O_RDONLY);
	if (fd < 0)
        return (NULL);
	*height = count_lines(fd);
    close(fd);
	fd = open(path, O_RDONLY);
	result = malloc(sizeof(char *) * (*height + 1));
	if (!result)
		return	(NULL);
	fill_result(fd, result);
	close(fd);
    return (result);
}

int  is_rectangular(t_map *map)
{
    int i;
    int len;

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

int  check_walls(t_map *map)
{
    int i;

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

int  check_characters(t_map *map)
{
	int		y;
	int		x;
	char	c;

	map->collectibles = 0;
	map->players = 0;
	map->exits = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			c = map->arr[y][x];
			if (!check_characters_helper(c, &map->collectibles, &map->players, &map->exits))
				return (0);
			x++;
		}
		y++;
	}
	if (map->players != 1 || map->exits != 1 || map->collectibles < 1)
		return (0);
	return (1);
}

t_map   *get_map(char *path)
{
    t_map   *map;

    map = malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->arr = read_lines(path, &map->height);
    if (!map->arr)
        return (NULL);

    if (!is_rectangular(map))
        return (printf("Error: Map is not rectangular\n"), free_map(map), NULL);
    if (!check_walls(map))
        return (printf("Error: Map not surrounded by walls\n"), free_map(map), NULL);
    if (!check_characters(map))
        return (printf("Error: Invalid characters or counts\n"), free_map(map), NULL);

    return (map);
}

void    free_map(t_map *map)
{
    int i = 0;
    if (!map)
        return;
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