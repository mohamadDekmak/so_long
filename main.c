/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:07:55 by mdekmak           #+#    #+#             */
/*   Updated: 2025/11/09 14:07:55 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx_linux/mlx.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_putstr_fd("Error\nUsage: ./so_long map.ber\n", 1), 1);
	if (!check_extension(argv[1]))
		ft_putstr_fd("Error\nInvalid file extension (.ber)\n", 1);
	if (!check_extension(argv[1]))
		return (1);
	game.map = get_map(argv[1]);
	if (!game.map)
		return (0);
	if (!check_valid_path(game.map))
		return (ft_putstr_fd("Error\nNo valid path\n", 1),
			free_map(game.map), 0);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map->width * TILE_SIZE,
			game.map->height * TILE_SIZE, "So Long");
	game.moves = 0;
	game.collectibles_count = game.map->collectibles;
	load_images(&game);
	render_map(&game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_loop(game.mlx);
	return (0);
}
