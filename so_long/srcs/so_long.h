/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:39:56 by bokim             #+#    #+#             */
/*   Updated: 2021/08/30 14:50:49 by bokim            ###   ########.fr       */
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

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_map
{
	int	col;
	int	row;
	char	*file;
}	t_map;

typedef struct s_img
{
	void *ptr;
	int *data;
	int width;
	int height;
}	t_img;

typedef struct s_player
{
	int	life;
	int	item;
	int	moves;
}	t_player;

typedef struct s_game
{
	void *mlx;
	void *win;
	t_map map;
	t_img player;
	t_img ground;
	t_img wall;
	t_img item;
	t_img portal;
}	t_game;

void	init_game(t_game *game);
void	init_window(t_game *game);

#endif