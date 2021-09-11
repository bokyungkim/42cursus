/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:00:02 by bokim             #+#    #+#             */
/*   Updated: 2021/09/12 00:08:47 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_window(t_game *game)
{
	int	width;
	int	height;
	
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_map(game);
		error_end("mlx initialize error");
	}
	width = game->map.col * TILE_SIZE;
	height = game->map.row * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
		error_end("window initialize error");
}

void	init_game(t_game *game)
{
	init_window(game);
	init_all_structs(game);
	//모든 구조체 요소들 init 하기
	// draw_map(game);
}