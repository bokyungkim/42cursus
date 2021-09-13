/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:35:25 by bokim             #+#    #+#             */
/*   Updated: 2021/09/13 22:47:27 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map.map[y - 1][x] != '1' && game->map.map[y - 1][x] != 'E')
	{
		game->moves++;
		game->map.map[y][x] = '0';
		game->map.map[y - 1][x] = 'P';
		draw_map(game);
		return (0);
	}
	if (game->map.map[y - 1][x] == 'E')
	{
		if (check_item(game) == 0)
			return (0);
	}
	return (1);
}

int		move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map.map[y + 1][x] != '1' && game->map.map[y - 1][x] != 'E')
	{
		game->moves++;
		game->map.map[y][x] = '0';
		game->map.map[y + 1][x] = 'P';
		draw_map(game);
		return (0);
	}
	if (game->map.map[y + 1][x] == 'E')
	{
		if (check_item(game) == 0)
			return (0);
	}
	return (1);
}

int		move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map.map[y][x - 1] != '1' && game->map.map[y - 1][x] != 'E')
	{
		game->moves++;
		game->map.map[y][x] = '0';
		game->map.map[y][x - 1] = 'P';
		draw_map(game);
		return (0);
	}
	if (game->map.map[y][x - 1] == 'E')
	{
		if (check_item(game) == 0)
			return (0);
	}
	return (1);
}

int		move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map.map[y][x + 1] != '1' && game->map.map[y - 1][x] != 'E')
	{
		game->moves++;
		game->map.map[y][x] = '0';
		game->map.map[y][x + 1] = 'P';
		draw_map(game);
		return (0);
	}
	if (game->map.map[y][x + 1] == 'E')
	{
		if (check_item(game) == 0)
			return (0);
	}
	return (1);
}
