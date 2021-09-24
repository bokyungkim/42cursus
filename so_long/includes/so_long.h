/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:39:56 by bokim             #+#    #+#             */
/*   Updated: 2021/09/24 21:22:18 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define TILE_SIZE 64
# define PLAYER_IMG "textures/penguin.xpm"
# define ITEM_IMG "textures/icecream.xpm"
# define WALL_IMG "textures/tree1.xpm"
# define GROUND_IMG "textures/ground2.xpm"
# define PORTAL_IMG "textures/portal1.xpm"

typedef struct s_map
{
	int	col;
	int	row;
	char	*filename;
	char	**map;
}	t_map;

typedef struct s_game
{
	void *mlx;
	void *win;
	t_map map;
	void	*player;
	void	*item;
	void	*ground;
	void	*wall;
	void	*portal;
	int		moves;
	int		x;
	int		y;
	int		game_status;
}	t_game;

//main.c
void	error_end(char *str);
int		close_game(t_game *game);
int		deal_key(int key_code, t_game *game);
int		end_game(t_game *game);

//init_game.c
void	init_game(t_game *game);
void	init_window(t_game *game);
void	init_imgs_ints(t_game *game);
void	set_coord(t_game *game, int x, int y);
void	draw_moves(t_game *game);

//map_read.c
void	read_map_file(t_game *game, char *filename);
void	get_map_info(t_game *game, int fd, char *filename);
void	fill_map(t_game *game, int fd);
void	init_map(t_game *game, char *filename);

//free.c
int		free_map(t_game *game);
int		free_imgs(t_game *game);

//map_draw.c
void	draw_map(t_game *game);
void	draw_ground(t_game *game, int x, int y);
void	draw_wall(t_game *game, int x, int y);
void	draw_item(t_game *game, int x, int y);
void	draw_player_n_portal(t_game *game, int x, int y, char c);

//check.c
int		check_imgs(t_game *game);
int		check_item(t_game *game);

//check_map.c
int		check_map_content(char *line);
void	check_extension(char *filename, char *ext);
void	check_map_condition(t_map map);
int		get_char_num(t_map map, char c);

//move.c
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);
void	add_mvs_n_mv_player(int x, int y, t_game *game);

#endif