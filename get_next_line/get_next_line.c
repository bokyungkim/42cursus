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

int     lstadd_back(t_list *lst, t_list *new)
{
	if (!new || !lst)
		return (-1);
	else if (lst == NULL)
		lst->next = new;
	else
    {
        while (lst->next != NULL)
            lst = lst->next;
        lst->next = new;
    }
    return (0);
}

int     init_fd(t_list **head, t_list **current, int fd)
{
    if (!(*head))
    {
        *head = (t_list *)malloc(sizeof(t_list));
        if (!(*head))
            return (-1);
        **head = (t_list){ .fd = 0, .backup = NULL, .next = NULL };
    }
    while ((*head)->fd != fd && !((*head)->next))
        head = &((*head)->next);
    if ((*head)->fd == fd)
        return (1);
    *current = (t_list *)malloc(sizeof(t_list));
    if (!current)
        return (-1);
    **current = (t_list){ .fd = fd, .backup = NULL, .next = NULL };
    if (lstadd_back(*head, *current) == -1)
        return (-1);
}

int		get_next_line(int fd, char **line)
{
    static t_list   *head_node;
    t_list          *current_node;
    int             read_size;
    char            buff[BUFFER_SIZE + 1];

    if (fd < 0 || fd > 256 || !line || BUFFER_SIZE <= 0 || (read(fd, buff, 0) == -1)
                || init_fd(&head_node, &current_node, fd) == -1)
        return (-1);
    while ((read_size = read(current_node->fd, buff, BUFFER_SIZE)) >= 0)
    {
        if (read_size == 0)
        {
            //나중에 채우자
        }
    }
}
