/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:48:05 by bokim             #+#    #+#             */
/*   Updated: 2021/05/18 15:55:01 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
    char            buff[BUFFER_SIZE + 1];

    if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
        return (-1);
}
