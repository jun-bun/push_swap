/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 01:01:15 by juwong            #+#    #+#             */
/*   Updated: 2018/09/21 20:52:40 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			merge_sort(t_tower *tower)
{
	t_min       mins;
	int         len;
	int			next_distance;
	enum		e_move move;

	len = ft_lst_len(tower->a);
	while(len >= 2 && !isascending(tower->a))
	{
		mins = get_next_mins(tower->a);
			next_distance = (ft_abs(find_distance(mins.a_i, mins.len))) < (ft_abs(find_distance(mins.b_i, mins.len))) ? mins.a_i : mins.b_i;
		move = next_distance < 0 ? rra : ra;
		while (*(int*)tower->a->content != mins.a && *(int*)tower->a->content != mins.b)
			ps_move(tower, move);
		ps_move(tower, pb);
		mins = getmin(tower->a);
		move = find_distance(mins.a_i, mins.len) < 0 ? rra : ra;
		while (*(int*)tower->a->content != mins.a)
			ps_move(tower, move);
		ps_move(tower, pb);
		len = ft_lst_len(tower->a);
	}
	while (tower->b)
	{
		if (isascending(tower->a))
		{
			ps_move(tower, pa);
			ps_move(tower, pa);
		}
		else if (*(int*)tower->b->content < *(int*)tower->b->next->content)
			ps_move(tower, ss);
		else
			ps_move(tower, sa);
	}
}

