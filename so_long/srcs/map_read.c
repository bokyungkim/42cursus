/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 23:26:12 by bokim             #+#    #+#             */
/*   Updated: 2021/10/05 02:28:15 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/so_long.h"

static void	get_map_info(t_game *game, int fd, char *filename)
{
	char	*line;
	int		gnl_ret;
	int		tmp_col;
	int		row;

	line = NULL;
	game->map.filename = filename;
	gnl_ret = get_next_line(fd, &line);
	if (gnl_ret == -1 || !line)
		error_end(game, "Invalid file content");
	game->map.col = check_map_content(game, line);
	free_line(line);
	row = 1;
	while (gnl_ret == 1)
	{
		gnl_ret = get_next_line(fd, &line);
		tmp_col = check_map_content(game, line);
		free_line(line);
		if (tmp_col != game->map.col)
			error_end(game, "Different column number in map");
		row++;
	}
	check_gnl_ret(gnl_ret, row, game);
	close(fd);
}

static void	fill_map(t_game *game, int fd)
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
		if (gnl_ret == -1 || !line)
			error_end(game, "GNL error");
		while (j < game->map.col)
		{
			game->map.map[i][j] = line[j];
			j++;
		}
		free_line(line);
		i++;
	}
}

static void	init_map(t_game *game, char *filename)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_end(game, "File open error");
	game->map.map = malloc(sizeof(char *) * game->map.row);
	if (!game->map.map)
	{
		game->map.map = NULL;
		error_end(game, "Map malloc error");
	}
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
}

void	read_map_file(t_game *game, char *filename)
{
	int	fd;

	if (check_extension(filename, "ber") == -1)
		error_end(game, "Wrong filename extension");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_end(game, "File Open Error");
	get_map_info(game, fd, filename);
	init_map(game, filename);
	if (check_map_condition(game->map) == -1)
	{
		free_map(game);
		error_end(game, "Wrong map content");
	}
}
