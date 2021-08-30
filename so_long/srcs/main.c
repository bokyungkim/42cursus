/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:40:07 by bokim             #+#    #+#             */
/*   Updated: 2021/08/30 17:13:50 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void error_end(char *str)
{
	ft_putstr_fd("Error:\t", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

int is_ber(char *file)
{
	int i;
	int len;

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

int main(int argc, char **argv)
{
	t_game *game;

	if (argc != 2)
		error_end("Wrong number of arguments");
	if (is_ber(argv[1]) == 0)
		error_end("Wrong filename extension");
	init_game(game);
	return (0);
}
