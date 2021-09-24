/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 21:10:09 by bokim             #+#    #+#             */
/*   Updated: 2021/09/24 21:22:48 by bokim            ###   ########.fr       */
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

int	get_char_num(t_map map, char c)
{
	int	i;
	int	j;
	int	ret;

	ret = 0;
	i = 0;
	while (i < map.row)
	{
		j = 0;
		while (j < map.col)
		{
			if (map.map[i][j] == c)
				ret += 1;
			j++;
		}
		i++;
	}
	return (ret);
}

void	check_map_condition(t_map map)
{
	int	portal;
	int	player;
	int	item;

// 벽으로 둘러싸인 거 체크하기 구현 필요

	portal = get_char_num(map, 'E');
	player = get_char_num(map, 'P');
	item = get_char_num(map, 'C');
	if (portal == 0 || player == 0 || item == 0)
		error_end("Wrong map content : check Portal or Player or Item");
}
