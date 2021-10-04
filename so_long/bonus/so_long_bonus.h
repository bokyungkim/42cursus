/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:39:56 by bokim             #+#    #+#             */
/*   Updated: 2021/10/05 02:39:19 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17
# define END 1
# define RUNNING 0
# define NO_MORE_ITEM 1
# define HAS_ITEM 0

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define TILE_SIZE 64
# define PLAYER_IMG "textures/penguin.xpm"
# define ITEM_IMG "textures/icecream.xpm"
# define WALL_IMG "textures/tree.xpm"
# define GROUND_IMG "textures/ground.xpm"
# define PORTAL_IMG "textures/portal.xpm"

typedef struct s_map
{
	int		col;
	int		row;
	char	*filename;
	char	**map;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
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
void	error_end(t_game *game, char *str);
int		close_game(t_game *game);
int		deal_key(int key_code, t_game *game);

//init_game.c
void	init_game(t_game *game);
void	set_coord(t_game *game, int x, int y);
void	draw_moves(t_game *game);

//map_read.c
void	read_map_file(t_game *game, char *filename);

//free.c
int		free_map(t_game *game);
int		free_imgs(t_game *game);
void	free_line(char *line);

//map_draw.c
int		draw_map(t_game *game);

//check.c
int		check_imgs(t_game *game);
int		check_item(t_game *game);
int		check_extension(char *filename, char *ext);
int		check_gnl_ret(int gnl_ret, int row, t_game *game);

//check_map.c
int		check_map_content(t_game *game, char *line);
int		check_map_condition(t_map map);
int		check_map_wall(t_map map);

//move.c
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);

#endif