/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:48:05 by bokim             #+#    #+#             */
/*   Updated: 2021/09/07 15:31:55 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	free_backup(char **backup, int ret)
{
	if (*backup)
	{
		free(*backup);
		*backup = NULL;
	}
	return (ret);
}

static int	read_until_nl(int fd, char **backup)
{
	int		len;
	int		ret;
	char	*tmp;

	len = ft_strlen(*backup);
	tmp = (char *)malloc(sizeof(char) * (len + BUFFER_SIZE + 1));
	if (!tmp)
		return (free_backup(backup, -1));
	ft_memcpy(tmp, *backup, len);
	ret = read(fd, tmp + len, BUFFER_SIZE);
	if (ret == -1)
	{
		free_backup(backup, 0);
		free(tmp);
		tmp = NULL;
		return (-1);
	}
	*(tmp + len + ret) = '\0';
	free_backup(backup, 0);
	*backup = tmp;
	return (ret);
}

static int	split_line(char **line, char **backup)
{
	char	*nl_ptr;
	char	*tmp;

	tmp = *backup;
	nl_ptr = ft_strchr(*backup, '\n');
	*nl_ptr = '\0';
	*line = ft_strdup(*backup);
	if (!*line)
		return (free_backup(backup, -1));
	*backup = ft_strdup(nl_ptr + 1);
	if (!*backup)
		free_backup(backup, 0);
	free(tmp);
	tmp = NULL;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char		*backup[OPEN_MAX];
	int				read_size;

	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(backup[fd]))
	{
		backup[fd] = ft_strdup("");
		if (!(backup[fd]))
			return (-1);
	}
	read_size = read_until_nl(fd, &backup[fd]);
	while (!(ft_strchr(backup[fd], '\n')) && (read_size > 0))
		read_size = read_until_nl(fd, &backup[fd]);
	if (read_size == -1)
		return (free_backup(&backup[fd], -1));
	if ((ft_strchr(backup[fd], '\n')))
		return (split_line(line, &backup[fd]));
	*line = ft_strdup(backup[fd]);
	if (!*line)
		return (-1);
	free_backup(&backup[fd], 0);
	return (0);
}
