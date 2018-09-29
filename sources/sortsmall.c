/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortsmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:03:36 by juwong            #+#    #+#             */
/*   Updated: 2018/09/29 00:07:08 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	sort2(t_tower *tower)
{
	char	x;

	x = 0;
	if (ft_lst_len(tower->a) >= 2)
		if (*(int*)tower->a->content > *(int*)tower->a->next->content)
			x = 1;
	if (ft_lst_len(tower->b) >= 2)
		if (*(int*)tower->b->content < *(int*)tower->b->next->content)
			x = x | 2;
	if (x == 3)
		ps_move(tower, ss);
	else if (x == 2)
		ps_move(tower, sb);
	else if (x == 1)
		ps_move(tower, sa);
}

void    sort3(t_tower *tower)
{
	int	max_index;

	while (!isascending(tower->a))
	{	
		max_index = get_index(tower->a, get_max(tower->a, 3));
		if (max_index == 2)
		{
			ps_move(tower, ra);
			if (isascending(tower->a))
				break;
			sort2(tower);
			if (isascending(tower->a))
				break;
			ps_move(tower, rra);
			if (isascending(tower->a))
				break;	
		}
		else
			sort2(tower);
	}
}

void	sortsmall(t_tower *tower)
{
	int		len;

	while (!isascending(tower->a))
	{
		len = ft_lst_len(tower->a);
		if (len == 3)
			sort3(tower);
		else if (len == 2)
			sort2(tower);
		else if (len > 3)
		{
			if (*(int*)tower->a->content >= get_pivot(3, 1, tower->a))
				ps_move(tower, ra);
			else
				ps_move(tower, pb);
		}
	}
	insertion_sort(tower);
}
