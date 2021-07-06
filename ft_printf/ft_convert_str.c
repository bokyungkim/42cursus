/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 00:03:46 by bokim             #+#    #+#             */
/*   Updated: 2021/07/06 17:15:07 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* precision에 따라 문자열 출력 */
static void		ft_cutnput_str(char *str, int size)
{
	int		i;

	i = 0;
	if ((int)ft_strlen(str) >= size)
		ft_putstr_fd(str, 1);
	else
	{
		while (i < size)
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	}
	return ;
}

/* 특징 : precision이 존재한다면, 문자열이 그보다 길다고 해도 precision만큼만 출력
		 받아온 문자열이 NULL이라면 출력할 문자열은 "(null)"로 세팅됨
		 0 flag는 undefined behavior */
int		ft_convert_str(char *str, t_opt *option)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	//precision 재설정
	if (option->precision > len || option->precision <= -1) //음수일 때는 precision 사용하지 않을 때임
		option->precision = len;
	if (option->width <= option->precision)
		ft_cutnput_str(str, option->precision);
	else if (option->left == 0)
	{
		ft_putspace(option->width - option->precision);
		ft_cutnput_str(str, option->precision);
	}
	else if (option->left == 1)
	{
		ft_cutnput_str(str, option->precision);
		ft_putspace(option->width - option->precision);
	}
	if (option->width > option->precision)
		return (option->width);
	else
		return (option->precision);
}
