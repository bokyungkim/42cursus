/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:52:08 by bokim             #+#    #+#             */
/*   Updated: 2021/10/05 01:49:38 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.row)
	{
		if (game->map.map[i])
		{
			free(game->map.map[i]);
			game->map.map[i] = NULL;
		}
		i++;
	}
	if (game->map.map)
	{
		free(game->map.map);
		game->map.map = NULL;
	}
	return (0);
}

int	free_imgs(t_game *game)
{
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->item)
		mlx_destroy_image(game->mlx, game->item);
	if (game->ground)
		mlx_destroy_image(game->mlx, game->ground);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->portal)
		mlx_destroy_image(game->mlx, game->portal);
	return (0);
}

void	free_line(char *line)
{
	free(line);
	line = NULL;
}
