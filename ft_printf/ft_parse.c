/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 20:52:20 by bokim             #+#    #+#             */
/*   Updated: 2021/07/02 20:52:57 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_flag(char c, t_opt *option)
{
	if (c == '-')
		option->minus = 1;
	else if (c == '0')
		option->zero = 1;
	else
		option->star = 1;
	if (option->minus == 1 && option->zero == 1)
		option->zero = 0;
	return (option->index + 1);
}

int		ft_parse_digit(char c, t_opt *option)
{
	if (option->precision == -1) //width일 때
		option->width = option->width * 10 + ft_atoi(c);
	else //precision일 때
		option->precision = option->precision * 10 + ft_atoi(c);
	return (option->index + 1);
}

int		ft_parse_type(char c, t_opt *option)
{
	option->type = (int)c;
	return (option->index + 1);
}


int		ft_parse(char *input, t_opt *option, va_list ap)
{
	int		cnt;
	int		*idx;

	cnt = 0;
	idx = option->index;
	while (ft_strchr(FLAG, input[*idx]) && input[*idx] != '\0') //flag일 때
		*idx = ft_parse_flag(input[*idx], option);
	while (ft_strchr(DIGIT, input[*idx]) && input[*idx] != '\0') //width일 때
		*idx = ft_parse_digit(input[*idx], option);
	if (input[*idx] == '.')
	{
		option->precision = 0;
		(*idx)++;
	}
	while (ft_strchr(DIGIT, input[*idx]) && input) //precision일 때
		*idx = ft_parse_digit(input[*idx], option);
	if (ft_strchr(TYPE, input[*idx]) && input) //specifier일 때
		*idx = ft_parse_type(input[*idx], option);
	else //specifier가 없으면
		return (-1);
	cnt += ft_conversion((char)option->type, option, ap); //conversion 필요부분 출력
	return 	(cnt);
}