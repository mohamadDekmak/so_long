#include "so_long.h"
#include "mlx_linux/mlx.h"

void	load_images(t_game *game)
{
	int w;
	int h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/fence.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "assets/spike.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "assets/dog_house.xpm", &w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "assets/bone.xpm", &w, &h);
}

void	draw_tile(t_game *g, int x, int y, char tile)
{
	// Always draw floor first
	mlx_put_image_to_window(g->mlx, g->win, g->img_floor, x * TILE_SIZE, y * TILE_SIZE);
	
	// Then draw objects on top
	if (tile == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->img_player, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img_exit, x * TILE_SIZE, y * TILE_SIZE);
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
