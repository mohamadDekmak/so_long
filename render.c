/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:36:00 by mdekmak           #+#    #+#             */
/*   Updated: 2025/11/09 15:36:00 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx_linux/mlx.h"

void	load_images(t_game *game)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/fence.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &w, &h);
	game->img_player_right = mlx_xpm_file_to_image(game->mlx,
			"textures/spike_right.xpm", &w, &h);
	game->img_player_left = mlx_xpm_file_to_image(game->mlx,
			"textures/spike.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/dog_house.xpm", &w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/bone.xpm", &w, &h);
	game->facing_right = 1;
}

void	draw_tile(t_game *g, int x, int y, char tile)
{
	void	*player_sprite;

	mlx_put_image_to_window(g->mlx, g->win, g->img_floor,
		x * TILE_SIZE, y * TILE_SIZE);
	if (tile == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img_wall,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
	{
		if (g->facing_right)
			player_sprite = g->img_player_right;
		else
			player_sprite = g->img_player_left;
		mlx_put_image_to_window(g->mlx, g->win, player_sprite,
			x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (tile == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img_exit,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img_collectible,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			draw_tile(game, x, y, game->map->arr[y][x]);
			x++;
		}
		y++;
	}
	display_moves(game);
}

void	display_moves(t_game *game)
{
	char	*moves_str;
	char	*moves_num;

	moves_num = ft_itoa(game->moves);
	if (!moves_num)
		return ;
	moves_str = ft_strjoin("Moves: ", moves_num);
	free(moves_num);
	if (!moves_str)
		return ;
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, moves_str);
	free(moves_str);
}
