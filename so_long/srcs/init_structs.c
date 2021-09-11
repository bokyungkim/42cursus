/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:32:15 by bokim             #+#    #+#             */
/*   Updated: 2021/09/11 21:52:29 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_player(t_game *game)
{
	game->player.img = init_img_ptr(game, PLAYER_IMG);
	if (!game->player.img)
	{
		free_map(game);
		error_end("Image initialize error");
	}
	game->player.item = 0;
	game->player.moves = 0;
}

void	init_imgs(t_game *game)
{
}

void	init_all_structs(t_game	*game)
{
	init_player(game);
	init_imgs(game);
}