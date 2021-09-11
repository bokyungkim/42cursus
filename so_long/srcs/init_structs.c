/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:32:15 by bokim             #+#    #+#             */
/*   Updated: 2021/09/12 00:52:53 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_imgs(t_game *game)
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

void	init_all_structs(t_game	*game)
{
	init_imgs(game);
}