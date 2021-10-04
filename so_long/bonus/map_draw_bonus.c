/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:16:06 by bokim             #+#    #+#             */
/*   Updated: 2021/10/05 02:38:57 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_ground(t_game *game, int x, int y)
{
	x *= TILE_SIZE;
	y *= TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->win, game->ground, x, y);
}

static void	draw_wall(t_game *game, int x, int y)
{
	x *= TILE_SIZE;
	y *= TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->win, game->wall, x, y);
}

static void	draw_item(t_game *game, int x, int y)
{
	x *= TILE_SIZE;
	y *= TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->win, game->item, x, y);
}

static void	draw_player_n_portal(t_game *game, int x, int y, char c)
{
	x *= TILE_SIZE;
	y *= TILE_SIZE;
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->portal, x, y);
}

int	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			draw_ground(game, j, i);
			if (game->map.map[i][j] == '1')
				draw_wall(game, j, i);
			if (game->map.map[i][j] == 'C')
				draw_item(game, j, i);
			if (game->map.map[i][j] == 'P' || game->map.map[i][j] == 'E')
			{
				if (game->map.map[i][j] == 'P')
					set_coord(game, j, i);
				draw_player_n_portal(game, j, i, game->map.map[i][j]);
			}
			j++;
		}
	}
	draw_moves(game);
	return (0);
}
