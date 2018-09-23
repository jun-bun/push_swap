/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 01:03:52 by juwong            #+#    #+#             */
/*   Updated: 2018/09/16 01:09:13 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int     ft_lst_len(t_list *list)
{
	int     i;

	i = 0;
	if (!list)
		return (-1);
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}