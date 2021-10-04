/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:40:07 by bokim             #+#    #+#             */
/*   Updated: 2021/10/05 00:52:58 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_end(t_game *game, char *str)
{
	ft_putstr_fd("Error:\t", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	free_map(game);
	mlx_destroy_window(game->mlx, game->win);
	exit(1);
}

int	close_game(t_game *game)
{
	free_map(game);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		close_game(game);
	else if (key_code == KEY_W && game->game_status == RUNNING)
		move_up(game);
	else if (key_code == KEY_S && game->game_status == RUNNING)
		move_down(game);
	else if (key_code == KEY_A && game->game_status == RUNNING)
		move_left(game);
	else if (key_code == KEY_D && game->game_status == RUNNING)
		move_right(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_end(&game, "Wrong number of arguments");
	read_map_file(&game, argv[1]);
	init_game(&game);
	mlx_loop_hook(game.mlx, draw_map, &game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
