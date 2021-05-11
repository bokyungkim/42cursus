/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:58:43 by bokim             #+#    #+#             */
/*   Updated: 2021/05/11 15:51:37 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		i++;
	return (i);
}
