/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:27:27 by bokim             #+#    #+#             */
/*   Updated: 2021/09/11 21:55:57 by bokim            ###   ########.fr       */
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
	else if (ft_strncmp(ext, "png", 3) == 0 || ft_strncmp(ext, "PNG", 3) == 0)
	{
		if (ft_strncmp(filename + i, ".png", 4) != 0
			&& ft_strncmp(filename + i, ".PNG", 4) != 0)
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
