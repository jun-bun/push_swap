/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 23:25:13 by juwong            #+#    #+#             */
/*   Updated: 2018/09/15 20:30:38 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int isdupe(t_list *list, int num)
{
	while (list)
	{
		if (*(int*)list->content == num)
			return (1);	
		list = list->next;
	}
	return (0);
}