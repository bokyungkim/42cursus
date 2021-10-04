/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 21:10:09 by bokim             #+#    #+#             */
/*   Updated: 2021/10/05 02:22:03 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map_content(t_game *game, char *line)
{
	int	num;

	num = 0;
	while (line[num])
	{
		if (line[num] != '0' && line[num] != '1' && line[num] != 'C'
			&& line[num] != 'E' && line[num] != 'P')
			error_end(game, "Wrong char in map file");
		num++;
	}
	return (num);
}

int	check_map_wall(t_map map)
{
	int	i;

	i = 0;
	while (i < map.col)
	{
		if (map.map[0][i] != '1' || map.map[map.row - 1][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i < map.row)
	{
		if (map.map[i][0] != '1' || map.map[i][map.col - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

static int	get_char_num(t_map map, char c)
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

int	check_map_condition(t_map map)
{
	int	portal;
	int	player;
	int	item;

	portal = get_char_num(map, 'E');
	player = get_char_num(map, 'P');
	item = get_char_num(map, 'C');
	if (portal == 0 || player == 0 || item == 0 || check_map_wall(map) == -1)
		return (-1);
	return (0);
}
