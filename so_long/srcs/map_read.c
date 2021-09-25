/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 23:26:12 by bokim             #+#    #+#             */
/*   Updated: 2021/09/25 23:37:39 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/so_long.h"

void	get_map_info(t_game *game, int fd, char *filename)
{
	char	*line;
	int		gnl_ret;
	int		tmp_col;
	int		row;

	line = NULL;
	game->map.filename = filename;
	gnl_ret = get_next_line(fd, &line);
	game->map.col = check_map_content(game, line);
	row = 1;
	if (gnl_ret == -1 || !line)
		error_end(game, "Invalid file content");
	while (gnl_ret == 1)
	{
		gnl_ret = get_next_line(fd, &line);
		tmp_col = check_map_content(game, line);
		if (tmp_col != game->map.col)
			error_end(game, "Different column number in map");
		row++;
	}
	if (gnl_ret == 0)
		game->map.row = row;
	else if (gnl_ret == -1)
		error_end(game, "GNL error");
	close(fd);
}

void	fill_map(t_game *game, int fd)
{
	char	*line;
	int		gnl_ret;
	int		i;
	int		j;

	line = NULL;
	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret == -1)
			error_end(game, "GNL error");
		while (j < game->map.col)
		{
			game->map.map[i][j] = line[j];
			j++;
		}
		i++;
	}
}

void	init_map(t_game *game, char *filename)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_end(game, "File open error");
	game->map.map = malloc(sizeof(char *) * game->map.row);
	if (!game->map.map)
		error_end(game, "Map malloc error");
	while (i < game->map.row)
	{
		game->map.map[i] = malloc(sizeof(char) * game->map.col);
		if (!(game->map.map[i]))
		{
			free_map(game);
			error_end(game, "Map malloc error");
		}
		i++;
	}
	fill_map(game, fd);
	close(fd);
	// 나중에 꼭 free 해줍시다
}

void	read_map_file(t_game *game, char *filename)
{
	int	fd;

	if (check_extension(filename, "ber") == 0)
		error_end(game, "Wrong filename extension");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_end(game, "File Open Error");
	get_map_info(game, fd, filename);
	init_map(game, filename);
	if (check_map_condition(game->map) == 0)
		error_end(game, "Wrong map content");
}
