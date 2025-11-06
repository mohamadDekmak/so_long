#include "so_long.h"
#include "mlx_linux/mlx.h"

void	load_images(t_game *game)
{
	int w;
	int h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/fence.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &w, &h);
	game->img_player_right = mlx_xpm_file_to_image(game->mlx, "assets/spike_right.xpm", &w, &h);
	game->img_player_left = mlx_xpm_file_to_image(game->mlx, "assets/spike.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "assets/dog_house.xpm", &w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "assets/bone.xpm", &w, &h);
	game->facing_right = 1;
}

void	draw_tile(t_game *g, int x, int y, char tile)
{
	void	*player_sprite;
	
	// Always draw floor first
	mlx_put_image_to_window(g->mlx, g->win, g->img_floor, x * TILE_SIZE, y * TILE_SIZE);
	
	// Then draw objects on top
	if (tile == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
	{
		player_sprite = g->facing_right ? g->img_player_right : g->img_player_left;
		mlx_put_image_to_window(g->mlx, g->win, player_sprite, x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (tile == 'E')
	{
		if (g->map->collectibles == 0)
			mlx_put_image_to_window(g->mlx, g->win, g->img_exit, x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (tile == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
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
}
