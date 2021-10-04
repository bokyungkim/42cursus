/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:00:02 by bokim             #+#    #+#             */
/*   Updated: 2021/10/05 02:38:45 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 18, 24, 0x00660033, "MOVES : ");
	mlx_string_put(game->mlx, game->win, 70, 24, 0x00660033, moves);
	free(moves);
	moves = NULL;
	return ;
}

void	set_coord(t_game *game, int x, int y)
{
	game->x = x;
	game->y = y;
}

static void	init_window(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_map(game);
		error_end(game, "mlx initialize error");
	}
	width = game->map.col * TILE_SIZE;
	height = game->map.row * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
	{
		free_map(game);
		error_end(game, "window initialize error");
	}
}

static void	init_imgs_ints(t_game *game)
{
	int	w;
	int	h;

	game->player = mlx_xpm_file_to_image(game->mlx, PLAYER_IMG, &w, &h);
	game->item = mlx_xpm_file_to_image(game->mlx, ITEM_IMG, &w, &h);
	game->ground = mlx_xpm_file_to_image(game->mlx, GROUND_IMG, &w, &h);
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL_IMG, &w, &h);
	game->portal = mlx_xpm_file_to_image(game->mlx, PORTAL_IMG, &w, &h);
	game->moves = 0;
	game->game_status = RUNNING;
	if (check_imgs(game) == -1)
	{
		free_map(game);
		error_end(game, "Can't initialize image");
	}
}

void	init_game(t_game *game)
{
	init_window(game);
	init_imgs_ints(game);
}
