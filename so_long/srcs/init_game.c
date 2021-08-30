/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:00:02 by bokim             #+#    #+#             */
/*   Updated: 2021/08/30 14:31:36 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	init_window(t_game *game)
{
	int	width;
	int	height;
	
	game->mlx = mlx_init();
	if (!game->mlx)
		error_end();
	width = game->map.col * TILE_SIZE;
	height = game->map.row * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
		error_end();
}

void	init_game(t_game *game)
{
	init_window(game);
	//모든 구조체 요소들 init 하기
}