/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:09:57 by bokim             #+#    #+#             */
/*   Updated: 2021/07/01 22:50:07 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"
// %[flag][width].[precision][specifier]
# define FLAG "-0.*" //플래그 파싱에 사용
# define DIGIT "0123456789" //width, precision 파싱에 사용
# define CONVERSION "cspdiuxX%" //conversion 파싱에 사용

typedef struct	s_opt
{
	int		minus;
	int		zero;
	int		width;
	int		star;
	int		dot;
	int		precision;
	int		type;
}				t_opt;

int		ft_putchar(char *s, int fd);

#endif