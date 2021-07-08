/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 21:18:57 by mdenyse           #+#    #+#             */
/*   Updated: 2021/04/18 21:19:00 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;
	t_list	*cur;

	cur = *lst;
	if (!cur)
		return ;
	while (cur)
	{
		buf = cur->next;
		del(cur->content);
		free(cur);
		cur = buf;
	}
	*lst = NULL;
}
