/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 23:26:12 by bokim             #+#    #+#             */
/*   Updated: 2021/09/02 23:03:37 by bokim            ###   ########.fr       */
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
	else ;
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
		close(fd);
		error_end("Test");
	}
}