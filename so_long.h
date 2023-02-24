/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:36:35 by sum               #+#    #+#             */
/*   Updated: 2023/01/19 13:36:54 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/time.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# define TRUE 0
# define FALSE 1

# define LEFT 1
# define RIGHT 2

# define WALL		'1' 
# define FLOOR		'0'
# define COIN		'C'
# define PLAYER	'P'
# define EXIT		'E'
# define FLOWER	'*'
# define FLOWER2	'+'
# define WATER		'q'
# define WATER_L	'!'
# define WATER_M	'~'
# define WATER_R	'@'

# define W 		119
# define ARROW_UP 	65362
# define S		115
# define ARROW_DOWN	65364
# define A 		97
# define ARROW_LEFT	65361
# define D 		100
# define ARROW_RIGHT	65363

# define ESC 		65307

# define WALL_XPM		"assets/wall/wall"
# define FLOOR_XPM		"assets/other/floor"
# define FLOWER_XPM		"assets/other/flower"
# define FLOWER2_XPM		"assets/other/pinkflower"
# define WATER_XPM		"assets/other/water"
# define WATER_L_XPM		"assets/other/waterL"
# define WATER_M_XPM		"assets/other/waterM"
# define WATER_R_XPM		"assets/other/waterR"
# define COIN_XPM		"assets/coin/coin"
# define EXIT_XPM		"assets/exit/exit"
# define PLAYER_XPM		"assets/player/dino"
# define BANNER_XPM		"assets/other/banner.xpm"

typedef struct s_player {
	void	*img[34];
	int		w;
	int		h;
	int		x;
	int		y;
	int		ac[2];
	int		po[2];
	int		a[2];
	int		b[2];
	int		c[2];
	int		d[2];
	int		direction;
}		t_player;

typedef struct s_coin {
	void	*img[4];
	int		x;
	int		y;
	int		w;
	int		h;
}		t_coin;

typedef struct s_wall {
	void	*img[9];
	int		x;
	int		y;
	int		w;
	int		h;
}		t_wall;

typedef struct s_exit {
	void	*img[8];
	int		x;
	int		y;
	int		w;
	int		h;
}		t_exit;

typedef struct s_image {
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	ch[2];
	int		w;
	int		h;
}		t_image;

typedef struct s_game {
	void		*mlx;
	void		*win;
	long long	temp;
	char		**map;
	int			maph;
	int			mapw;
	int			move;
	int			c;
	int			e;
	int			p;
	t_image		*sprites;
	t_image		*banner;
	t_image		*floor;
	t_image		*flower;
	t_image		*flower2;
	t_image		*water;
	t_image		*water_r;
	t_image		*water_m;
	t_image		*water_l;
	t_wall		*wall;
	t_player	*player;
	t_image		*player2;
	t_exit		*exit;
	t_coin		*coin;
	t_alloc			*alloc;
	t_alloc			*img_alloc;
}		t_game;

void	exit_error(char *msg);
long long	check_timestamp(void);

int		kill_hook(int keycode, t_game *game);
int		keydown_hook(int keycode, t_game *game);
int		keyup_hook(int keycode, t_game *game);

int		player_actcode(int keycode);
void	player_act(int keycode, t_game *game);
void	player_disact(int keycode, t_game *game);

void	game_init(t_game *game, int arc);

void	map_read(t_game *game, char *filename);
void	map_check(t_game *game);
void	map_render(t_game *game);
int		map_check_parameter(t_game *game);
int		map_count_parameter(t_game *game);

void	init_mlx(t_game *game);
void	init_save_sprites(t_game *game);

void	sprite_init(t_game *game, char *buffer, t_image *map);
void	sprite_load(t_game *game, int i, int j, char *buffer, t_image *map);

void	wall_draw(t_game *game, int i, int j, char *buffer, t_image *map);

void	player_init(t_game *game);
void	player_position(t_game *game);
void	player_move_y(t_game *game);
void	player_move_x(t_game *game);
void	player_move_count(t_game *game);
void	player_draw(t_game *game);
int		*player_anim(t_game *game);
int		player_stay_img(int *last_img, t_game *game);
int		player_walk_img(int *last_img, t_game *game);
void	player_status(t_game *game);

void	coin_init(t_game *game, char *buffer, t_image *map);
void	coin_draw(t_game *game, int i, int j, char *buffer, t_image *map);

void	exit_init(t_game *game, char *buffer, t_image *map);
void	exit_draw(t_game *game, int i, int j, char *buffer, t_image *map);

void	create_map(t_game *game);
void	construct_image(char *buffer, int i, int j, t_image image2, t_image image);
t_image	generate_image(t_game game, char *path, t_alloc **alloc);

#endif