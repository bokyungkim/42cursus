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

char    *find_newline(char *buff, char c)
{
    char    *idx;

    idx = buff;
    while (*idx)
	{
        if (*idx == c)
            return (idx);
        idx++;
	}
    return (NULL);
}

int     cut_line(char **line, char **backup, char *buff, char *newline_ptr)
{
    *newline_ptr = '\0';
    if (*backup)
    {
        if (!(*line = ft_strdup(*backup)))
            return (-1);
        *line = ft_strjoin(*line, buff);
    }
    else
        if (!(*line = ft_strdup(buff)))
            return (-1);
    free(*backup);
    *backup = newline_ptr + 1;
    return (1);
}

int     return_all(char **line, char **backup, char *buff, int read_size)
{
    char    *newline_ptr;

    if (read_size < 0)
        return (-1);
    if (*backup && (newline_ptr = find_newline(*backup, '\n')))
        return (cut_line(line, backup, buff, newline_ptr));
    if (*backup)
    {
        *line = *backup;
        free(*backup);
        *backup = NULL;
    }
    else if (!(*line = ft_strdup("")))
    {
        free(*backup);
        *backup = NULL;
        return (-1);
    }
    return (0);  
}

int		get_next_line(int fd, char **line)
{
    static char     *backup[OPEN_MAX];
    char            buff[BUFFER_SIZE + 1];
    char            *newline_ptr;
    int             read_size;

    if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
        return (-1);
    while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0)
    {
        buff[read_size] = '\0';
        if (backup[fd])
            backup[fd] = ft_strjoin(backup[fd], buff);
        if ((newline_ptr = find_newline(buff, '\n')))
            return (cut_line(line, &backup[fd], buff, newline_ptr));
    }
    return (return_all(line, backup, buff, read_size));
}
