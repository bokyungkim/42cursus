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

char    *find_newline(char *backup, char c)
{
    char    *idx;

    idx = backup;
    while (idx)
	{
        if (*idx == c)
            return (idx);
        idx++;
	}
    return (NULL);
}

int     cut_line(char **line, char **backup, char *newline_idx)
{
    *newline_idx = '\0';
    if (!(*line = ft_strdup(*backup)))
    {
        free(*backup);
        *backup = NULL;
        return (-1);
    }
    free(*backup);
    *backup = newline_idx;
    return (1);
}

int     return_all(char **line, char **backup, int read_size)
{
    char    *newline_idx;

    if (read_size < 0)
        return (-1);
    if (*backup && (newline_idx = find_newline(*backup, '\n')))
        return (cut_line(line, backup, newline_idx));
    if (*backup)
    {
        *line = *backup;
        *backup = NULL;
    }
    else
    {
        if (!(*line = ft_strdup("")))
            return (-1);
    }
    return (0);  
}

int		get_next_line(int fd, char **line)
{
    static char     *backup[OPEN_MAX];
    char            buff[BUFFER_SIZE + 1];
    char            *newline_idx;
    int             read_size;

    if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
        return (-1);
    while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0)
    {
        buff[fd] = '\0';
        backup[fd] = ft_strjoin(backup[fd], buff);
        if ((newline_idx = find_newline(backup[fd], '\n')))
            return (cut_line(line, &backup[fd], newline_idx));
    }
    return (return_all(line, backup, read_size));
}
