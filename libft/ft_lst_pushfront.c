/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:40:56 by juwong            #+#    #+#             */
/*   Updated: 2018/09/11 14:11:30 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lst_pushfront(t_list **lst, void *content, size_t content_size)
{
	t_list		*new_elem;

	if (!lst)
		return ;
	if (*lst != NULL)
	{
		new_elem = ft_lstnew(content, content_size);
		new_elem->next = *lst;
		*lst = new_elem;
	}
	else
		*lst = ft_lstnew(content, content_size);
}
