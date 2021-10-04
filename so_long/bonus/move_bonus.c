/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:35:25 by bokim             #+#    #+#             */
/*   Updated: 2021/10/05 02:39:10 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	add_mvs_n_mv_player(int x, int y, t_game *game)
{
	game->moves++;
	game->map.map[y][x] = '0';
	draw_map(game);
}

int	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map.map[y - 1][x] != '1' && game->map.map[y - 1][x] != 'E')
	{
		game->map.map[y - 1][x] = 'P';
		add_mvs_n_mv_player(x, y, game);
		return (0);
	}
	if (game->map.map[y - 1][x] == 'E')
	{
		if (check_item(game) == NO_MORE_ITEM)
		{
			game->map.map[y - 1][x] = 'P';
			add_mvs_n_mv_player(x, y, game);
			game->game_status = END;
		}
	}
	return (0);
}

int	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map.map[y + 1][x] != '1' && game->map.map[y + 1][x] != 'E')
	{
		game->map.map[y + 1][x] = 'P';
		add_mvs_n_mv_player(x, y, game);
		return (0);
	}
	if (game->map.map[y + 1][x] == 'E')
	{
		if (check_item(game) == NO_MORE_ITEM)
		{
			game->map.map[y + 1][x] = 'P';
			add_mvs_n_mv_player(x, y, game);
			game->game_status = END;
		}
	}
	return (0);
}

int	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map.map[y][x - 1] != '1' && game->map.map[y][x - 1] != 'E')
	{
		game->map.map[y][x - 1] = 'P';
		add_mvs_n_mv_player(x, y, game);
		return (0);
	}
	if (game->map.map[y][x - 1] == 'E')
	{
		if (check_item(game) == NO_MORE_ITEM)
		{
			game->map.map[y][x - 1] = 'P';
			add_mvs_n_mv_player(x, y, game);
			game->game_status = END;
		}
	}
	return (0);
}

int	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map.map[y][x + 1] != '1' && game->map.map[y][x + 1] != 'E')
	{
		game->map.map[y][x + 1] = 'P';
		add_mvs_n_mv_player(x, y, game);
		return (0);
	}
	if (game->map.map[y][x + 1] == 'E')
	{
		if (check_item(game) == NO_MORE_ITEM)
		{
			game->map.map[y][x + 1] = 'P';
			add_mvs_n_mv_player(x, y, game);
			game->game_status = END;
		}
	}
	return (0);
}
