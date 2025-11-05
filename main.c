#include "so_long.h"
#include "mlx_linux/mlx.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (printf("Usage: ./so_long map.ber\n"), 1);
	if (!check_extension(argv[1]))
		return (printf("Error: Invalid file extension (.ber required)\n"), 1);

	game.map = get_map(argv[1]);
	if (!game.map)
		return (1);

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx,
			game.map->width * 64,
			game.map->height * 64,
			"So Long");

	game.moves = 0;
	find_player(&game);
	load_images(&game);
	render_map(&game);

	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_loop(game.mlx);
	return (0);
}
