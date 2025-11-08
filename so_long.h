#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_map
{
	char	**arr;
	int		width;
	int		height;
	int		collectibles;
	int		players;
	int		exits;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	void	*img_wall;
	void	*img_floor;
	void	*img_player_right;
	void	*img_player_left;
	void	*img_exit;
	void	*img_collectible;
	int		player_x;
	int		player_y;
	int		moves;
	int		facing_right;
	int		collectibles_count;
}			t_game;

t_map	*get_map(char *path);
void	free_map(t_map *map);
int		check_extension(char *filename);
void	load_images(t_game *game);
void	render_map(t_game *game);
void	find_player(t_game *game);
int		handle_keypress(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		check_valid_path(t_map *map);
void	display_moves(t_game *game);

#endif
