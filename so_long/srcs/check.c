/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:27:27 by bokim             #+#    #+#             */
/*   Updated: 2021/09/24 21:10:06 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_imgs(t_game *game)
{
	if (!game->player || !game->item || !game->ground
		|| !game->wall || !game->portal)
	{
		free_imgs(game);
		return (0);
	}
	return (1);
}

int	check_item(t_game *game)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			if (game->map.map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}