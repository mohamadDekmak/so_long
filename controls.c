/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:27:39 by mdekmak           #+#    #+#             */
/*   Updated: 2025/11/09 12:27:39 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx_linux/mlx.h"

#define KEY_ESC 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_LEFT 65361
#define KEY_RIGHT 65363

int	close_game(t_game *game)
{
	if (game->img_player_right)
		mlx_destroy_image(game->mlx, game->img_player_right);
	if (game->img_player_left)
		mlx_destroy_image(game->mlx, game->img_player_left);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map);
	exit(0);
}

void	move_player_helper(char tile, t_game *game)
{
	if (tile == 'C')
		game->collectibles_count--;
	if (tile == 'E' && game->collectibles_count == 0)
	{
		printf("You won in %d moves!\n", game->moves + 1);
		close_game(game);
	}
	game->map->arr[game->map->player.y][game->map->player.x] = 'P';
	game->moves++;
	printf("Moves: %d\n", game->moves);
}

void	move_player(t_game *game, int dx, int dy)
{
	t_point	new_pos;
	char	tile;

	if (dx > 0)
		game->facing_right = 1;
	else if (dx < 0)
		game->facing_right = 0;
	new_pos.x = game->map->player.x + dx;
	new_pos.y = game->map->player.y + dy;
	if (new_pos.x < 0 || new_pos.x >= game->map->width
		|| new_pos.y < 0 || new_pos.y >= game->map->height)
		return ;
	tile = game->map->arr[new_pos.y][new_pos.x];
	if (tile == '1')
		return ;
	if (tile == 'E' && game->collectibles_count > 0)
		return ;
	game->map->arr[game->map->player.y][game->map->player.x] = '0';
	game->map->player = new_pos;
	move_player_helper(tile, game);
	render_map(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 1, 0);
	return (0);
}
