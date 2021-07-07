/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:09:57 by bokim             #+#    #+#             */
/*   Updated: 2021/07/07 20:03:54 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"
// %[flag][width].[precision][specifier]
# define FLAG "-0" //플래그 파싱에 사용
# define DIGIT "0123456789*" //width, precision 파싱에 사용
# define TYPE "cspdiuxX%" //specifier 파싱에 사용

typedef struct s_opt
{
	int		index;
	int		left;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	int		type;
}				t_opt;

int		ft_printf(const char *input, ...);
int		ft_putchar(char s, int fd);

/* parsing */
int		ft_parse_flag(char c, t_opt *option);
int		ft_parse_digit(char c, t_opt *option, va_list ap);
int		ft_parse_type(char c, t_opt *option);
int		ft_parse(char *input, t_opt *option, va_list ap);

/* conversion */
int		ft_conversion(int c, t_opt *option, va_list ap);
void	ft_putspace(int size);
void	ft_putzero(int size);
int		ft_get_numsize(int n, int base);
int		ft_convert_char(char c, t_opt *option);
int		ft_convert_str(char *str, t_opt *option);
int		ft_convert_int(int n, t_opt *option);
int		ft_convert_percent(t_opt *option);
int		ft_convert_unsigned(unsigned int n, t_opt *option);

#endif
