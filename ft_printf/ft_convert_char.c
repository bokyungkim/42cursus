/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 00:03:15 by bokim             #+#    #+#             */
/*   Updated: 2021/07/06 23:58:32 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 특징 : precision 무시, 0 flag는 undefined behavior */
int	ft_convert_char(char c, t_opt *option)
{
	int		len;

	len = 1;
	if (option->width > 1)
		len = option->width;
	if (option->left == 0)
	{
		ft_putspace(len - 1);
		ft_putchar_fd(c, 1);
	}
	else
	{
		ft_putchar_fd(c, 1);
		ft_putspace(len - 1);
	}
	return (len);
}