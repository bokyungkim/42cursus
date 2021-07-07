/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:03:20 by bokim             #+#    #+#             */
/*   Updated: 2021/07/07 20:03:03 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char s, int fd)
{
	ft_putchar_fd(s, fd);
	return (1);
}

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

void	ft_putzero(int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
}

void	ft_put_right(t_opt *option, int minus, int n, int num_size)
{
	ft_putspace(option->width - option->precision - minus);
	if (minus == 1)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
	}
	ft_putzero(option->precision - num_size);
	ft_putnbr_fd(n, 1);
}

void	ft_put_left(t_opt *option, int minus, int n, int num_size)
{
	if (minus == 1)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
	}
	ft_putzero(option->precision - num_size);
	ft_putnbr_fd(n, 1);
	ft_putspace(option->width - option->precision - minus);
}