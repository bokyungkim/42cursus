/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:27:27 by bokim             #+#    #+#             */
/*   Updated: 2021/10/01 18:56:01 by bokim            ###   ########.fr       */
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

int	check_extension(char *filename, char *ext)
{
	int	i;

	i = ft_strlen(filename) - 4;
	if (filename[i] != '.' || i <= 0)
		return (0);
	if (ft_strncmp(ext, "ber", 3) == 0 || ft_strncmp(ext, "BER", 3) == 0)
	{
		if (ft_strncmp(filename + i, ".ber", 4) != 0
			&& ft_strncmp(filename + i, ".BER", 4) != 0)
			return (0);
	}
	else if (ft_strncmp(ext, "xpm", 3) == 0 || ft_strncmp(ext, "XPM", 3) == 0)
	{
		if (ft_strncmp(filename + i, ".xpm", 4) != 0
			&& ft_strncmp(filename + i, ".XPM", 4) != 0)
			return (0);
	}
	else
		return (0);
	return (1);
}

int	check_gnl_ret(int gnl_ret, int row, t_game *game)
{
	if (gnl_ret == 0)
		game->map.row = row;
	else if (gnl_ret == -1)
	{
		free_map(game);
		error_end(game, "GNL error");
	}
	return (0);
}
