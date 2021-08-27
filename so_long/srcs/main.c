/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:40:07 by bokim             #+#    #+#             */
/*   Updated: 2021/08/27 16:58:40 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./so_long.h"

void	error_end(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	is_ber(char *file)
{
	int	i;
	int	len;

	len = ft_strlen(file);
	while (file[i] && file[i] != '.')
	{
		i++;
		len--;
	}
	if (ft_strncmp(file + i, ".ber", len) == 0
		|| ft_strncmp(file + i, ".BER", len) == 0)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	
	if (argc != 2)
		error_end();
	if (is_ber(argv[1]) == 0)
		error_end();
	game = init_game();
	return (0);
}
