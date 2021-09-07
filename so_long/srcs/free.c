/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:52:08 by bokim             #+#    #+#             */
/*   Updated: 2021/09/07 16:59:55 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_game *game)
{
	int	i;
	
	i = 0;
	while (i < game->map.col)
	{
		if (game->map.map[i])
		{
			free(game->map.map[i]);
			game->map.map[i] = NULL;
		}
		i++;
	}
	free(game->map.map);
	game->map.map = NULL;
}