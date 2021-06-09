/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:48:05 by bokim             #+#    #+#             */
/*   Updated: 2021/06/09 18:43:58 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int  read_until_nl(int fd, char **backup)
{
    int     len;
    int     ret;
    char    *tmp;

    len = ft_strlen(*backup);
    tmp = (char *)malloc(sizeof(char) * (len + BUFFER_SIZE + 1));
    if (!tmp)
        return (-1);
    ft_memcpy(tmp, *backup, len);
    ret = read(fd, tmp + len, BUFFER_SIZE);
    *(tmp + len + ret + 1) = '\0';
    free(*backup);
    *backup = tmp;
    return (ret);
}

static int  split_line(char **line, char **backup)
{
    int     len;
    char    *nl_ptr;
    char    *tmp;

    nl_ptr = ft_strchr(*backup, '\n');
    *nl_ptr = '\0';
    len = ft_strlen(nl_ptr + 1);
    *line = ft_strdup(*backup);
    if (!(*line))
        return (-1);
    tmp = (char *)malloc(sizeof(char) * (len + 1));
    if (!tmp)
    {
        free(*backup);
        *backup = NULL;
        return (-1);
    }
    ft_memcpy(tmp, nl_ptr + 1, len + 1);
    free(*backup);
    *backup = tmp;
    return (0);
}

int		get_next_line(int fd, char **line)
{
    static char     *backup[OPEN_MAX];
    int             read_size;

    if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0)
        return (-1);
    if (!(backup[fd]))
    {
        backup[fd] = ft_strdup("");
        if (!(backup[fd]))
            return (-1);
    }
    while (!(ft_strchr(backup[fd], '\n')) && ((read_size = read_until_nl(fd, &backup[fd])) > 0))
        ;
    if (read_size == -1)
        return (-1);
    else if ((ft_strchr(backup[fd], '\n')))
    {
        split_line(line, &backup[fd]);
        return (1);
    }
    else if (read_size == 0)
    {
        *line = ft_strdup(backup[fd]);
        if (!(*line))
            return (-1);
        return (0);
    }
    return (-1);
}
