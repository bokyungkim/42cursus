/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:27:27 by bokim             #+#    #+#             */
/*   Updated: 2021/09/13 00:54:17 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_extension(char *filename, char *ext)
{
	int	i;

	i = ft_strlen(filename) - 4;
	if (filename[i] != '.' || i <= 0)
		error_end("Wrong filename extension");
	if (ft_strncmp(ext, "ber", 3) == 0 || ft_strncmp(ext, "BER", 3) == 0)
	{
		if (ft_strncmp(filename + i, ".ber", 4) != 0
			&& ft_strncmp(filename + i, ".BER", 4) != 0)
			error_end("Wrong filename extension");
	}
	else if (ft_strncmp(ext, "xpm", 3) == 0 || ft_strncmp(ext, "XPM", 3) == 0)
	{
		if (ft_strncmp(filename + i, ".xpm", 4) != 0
			&& ft_strncmp(filename + i, ".XPM", 4) != 0)
			error_end("Wrong filename extension");
	}
	else
		error_end("Wrong filename extension");
}

int	check_map_content(char *line)
{
	int	num;

	num = 0;
	while (line[num])
	{
		if (line[num] != '0' && line[num] != '1' && line[num] != 'C'
			&& line[num] != 'E' && line[num] != 'P')
			error_end("Wrong char in map file");
		num++;
	}
	return (num);
}

int	check_imgs(t_game *game)
{
	if (!game->player || !game->item || !game->ground
		|| !game->wall || !game->portal)
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
	return (1);
}
