/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:00:02 by bokim             #+#    #+#             */
/*   Updated: 2021/09/13 21:29:07 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_coord(t_game *game, int x, int y)
{
	game->x = x;
	game->y = y;
}

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

void	init_imgs_ints(t_game *game)
{
	int	w;
	int	h;

	game->player = mlx_xpm_file_to_image(game->mlx, PLAYER_IMG, &w, &h);
	game->item = mlx_xpm_file_to_image(game->mlx, ITEM_IMG, &w, &h);
	game->ground = mlx_xpm_file_to_image(game->mlx, GROUND_IMG, &w, &h);
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL_IMG, &w, &h);
	game->portal = mlx_xpm_file_to_image(game->mlx, PORTAL_IMG, &w, &h);
	game->score = 0;
	game->moves = 0;
	if (check_imgs(game) == 0)
	{
		free_map(game);
		error_end("Can't initialize image");
	}
}

void	init_game(t_game *game)
{
	init_window(game);
	init_imgs_ints(game);
}