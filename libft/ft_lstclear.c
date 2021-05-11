/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:10:19 by bokim             #+#    #+#             */
/*   Updated: 2021/05/11 17:49:37 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!lst || !del)
		return ;
	tmp1 = *lst;
	tmp2 = tmp1;
	while (tmp2)
	{
		tmp1 = tmp1->next;
		del(tmp2->content);
		free(tmp2);
		tmp2 = tmp1;
	}
	*lst = NULL;
}
