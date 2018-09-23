/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 17:31:23 by juwong            #+#    #+#             */
/*   Updated: 2018/09/21 18:57:03 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insert_list_ascending(t_list **list, t_list	*node)
{
	t_list	*tmp;
	t_list	*previous;

	previous = NULL;
	tmp = *list;
	if (!*list)
	{
		*list = node;
		return ;
	}
	while(tmp)
	{
		if (*(int*)node->content < *(int*)tmp->content)
		{
			if (previous)
				previous->next = node;
			node->next = tmp;
			if (*(int*)(*list)->content > *(int*)node->content)
				*list = node;
			return ;
		}
		previous = tmp;
		tmp = tmp->next;
	}
	previous->next = node;
}

t_list      *sort_list(t_list *list)
{
	t_list	*new;
	t_list	*node;

	new = NULL;
	while(list)
	{
		node = ft_lstnew((int*)list->content, list->content_size);
		insert_list_ascending(&new, node);
		list = list->next;
	}
	return (new);
}

