/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:40:07 by bokim             #+#    #+#             */
/*   Updated: 2021/09/06 18:33:18 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void error_end(char *str)
{
	ft_putstr_fd("Error:\t", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		error_end("Wrong number of arguments");
	read_file(&game, argv[1]);
	init_game(&game);
	// mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	// mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_game, &game);
	// mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}
