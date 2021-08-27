/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:39:56 by bokim             #+#    #+#             */
/*   Updated: 2021/08/27 16:33:39 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../mlx/mlx.h"
#include "../libft/libft.h"

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_RELEASE 3
#define X_EVENT_KEY_EXIT 17

#define KEY_ESC 53
#define KEY_Q 12
#define KEY_E 14
#define KEY_W 13
#define KEY_R 15
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

typedef struct s_img
{
	void *img;
	int *data;

	int size_l;
	int bpp;
	int endian;
} t_img;

typedef struct s_game
{
	void *mlx;
	void *win;
	t_img player;
	t_img ground;
	t_img wall;
	t_img item;
	t_img door;
} t_game;

#endif