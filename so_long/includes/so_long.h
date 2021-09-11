/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:39:56 by bokim             #+#    #+#             */
/*   Updated: 2021/09/12 00:39:34 by bokim            ###   ########.fr       */
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
# define KEY_Q 12
# define KEY_E 14
# define KEY_W 13
# define KEY_R 15
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define TILE_SIZE 64
# define PLAYER_IMG "textures/player1.xpm"
# define ITEM_IMG "textures/item1.xpm"
# define WALL_IMG "textures/tree1.xpm"
# define GROUND_IMG "textures/ground1.xpm"
# define PORTAL_IMG "textures/portal1.xpm"

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

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
	int		score;
	int		moves;
}	t_game;

//main.c
void	error_end(char *str);

//init_game.c
void	init_game(t_game *game);
void	init_window(t_game *game);

//map_read.c
void	read_map_file(t_game *game, char *filename);
void	get_map_info(t_game *game, int fd, char *filename);
void	fill_map(t_game *game, int fd);
void	init_map(t_game *game, char *filename);

//free.c
void	free_map(t_game *game);

//init_structs.c
void	init_all_structs(t_game *game);
void	init_imgs(t_game *game);

//map_draw.c
void	draw_map(t_game *game);

//check.c
int		check_map_content(char *line);
void	check_extension(char *filename, char *ext);
int		check_imgs(t_game *game);

#endif