/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 23:26:12 by bokim             #+#    #+#             */
/*   Updated: 2021/09/06 18:34:02 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/so_long.h"

void	check_ber(char *filename)
{
	int i;

	i = ft_strlen(filename) - 4;
	if (filename[i] != '.' || i <= 0)
		error_end("Wrong filename extension");
	if (ft_strncmp(filename + i, ".ber", 4) != 0
		&& ft_strncmp(filename + i, ".BER", 4) != 0)
		error_end("Wrong filename extension");
}

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

void	init_map(t_game *game, int fd, char *filename)
{
	char	*line;
	int		gnl_ret;
	int		tmp_col;
	int		row;
	
	line = NULL;
	game->map.file = filename;
	/*
		gnl 반환 값
		1: 한 라인이 읽혔을 때
		0: EOF에 도달했을 때
		-1: 에러가 발생했을 때
	*/
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
	printf("map.col = %d\n", game->map.col);
	printf("map.row = %d\n", game->map.row);
}

void	read_file(t_game *game, char *filename)
{
	int	fd;

	check_ber(filename);
	fd = open(filename, O_RDONLY);
	if (fd <= 1)
		error_end("File Open Error");
	else
	{
		init_map(game, fd, filename);
		close(fd);
	}
}