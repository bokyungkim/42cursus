/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 20:55:25 by bokim             #+#    #+#             */
/*   Updated: 2021/07/03 00:21:22 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putspace(int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
}

int		ft_conversion(int c, t_opt *option, va_list ap)
{
	int		cnt;

	cnt = 0;
	if (c == 'c')
		cnt += ft_convert_char(va_arg(ap, int), option);
	else if (c == 's')
		cnt += ft_convert_str(va_arg(ap, char *), option);
}