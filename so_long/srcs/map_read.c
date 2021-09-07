/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 23:26:12 by bokim             #+#    #+#             */
/*   Updated: 2021/09/07 16:22:45 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/so_long.h"

int	check_right_char(char *line)
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

void	get_map_info(t_game *game, int fd, char *filename)
{
	char	*line;
	int		gnl_ret;
	int		tmp_col;
	int		row;

	line = NULL;
	game->map.filename = filename;
	gnl_ret = get_next_line(fd, &line);
	game->map.col = check_right_char(line);
	row = 1;
	if (gnl_ret == -1 || !line)
		error_end("Invalid file content");
	while (gnl_ret == 1)
	{
		gnl_ret = get_next_line(fd, &line);
		tmp_col = check_right_char(line);
		if (tmp_col != game->map.col)
			error_end("Different column number in map");
		row++;
	}
	if (gnl_ret == 0)
		game->map.row = row;
	else if (gnl_ret == -1)
		error_end("GNL error");
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
			error_end("GNL error");
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
		error_end("File open error");
	game->map.map = malloc(sizeof(char *) * game->map.row);
	if (!game->map.map)
		error_end("Map malloc error");
	while (i < game->map.row)
	{
		game->map.map[i] = malloc(sizeof(char) * game->map.col);
		if (!game->map.map[i])
		{
			free(game->map.map);
			game->map.map = NULL;
			error_end("Map malloc error");
		}
		i++;
	}
	fill_map(game, fd);
	close(fd);
}

void	read_file(t_game *game, char *filename)
{
	int	fd;
	int	i;

	i = ft_strlen(filename) - 4;
	if (filename[i] != '.' || i <= 0)
		error_end("Wrong filename extension");
	if (ft_strncmp(filename + i, ".ber", 4) != 0
		&& ft_strncmp(filename + i, ".BER", 4) != 0)
		error_end("Wrong filename extension");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_end("File Open Error");
	get_map_info(game, fd, filename);
	init_map(game, filename);
}
