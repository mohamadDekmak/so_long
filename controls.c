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

void	find_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->arr[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;
	char	tile;

	// Update facing direction
	if (dx > 0)
		game->facing_right = 1;
	else if (dx < 0)
		game->facing_right = 0;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x < 0 || new_x >= game->map->width || 
		new_y < 0 || new_y >= game->map->height)
		return ;

	tile = game->map->arr[new_y][new_x];
	if (tile == '1')
		return ;
	
	// Don't allow moving to exit until all collectibles are gathered
	if (tile == 'E' && game->map->collectibles > 0)
		return ;

	game->map->arr[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;

	if (tile == 'C')
		game->map->collectibles--;

	if (tile == 'E' && game->map->collectibles == 0)
	{
		printf("You won in %d moves!\n", game->moves + 1);
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}

	game->map->arr[new_y][new_x] = 'P';
	game->moves++;
	printf("Moves: %d\n", game->moves);
	render_map(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
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
