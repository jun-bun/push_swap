/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:58:52 by juwong            #+#    #+#             */
/*   Updated: 2018/09/26 23:24:18 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			swap(t_list	**list)
{
	t_list      *tmp;

	if (*list && (*list)->next)
	{
		tmp = *list;
		*list = (*list)->next;
		tmp->next = (*list)->next;
		(*list)->next = tmp;
	}
}

void			push(t_list **a, t_list **b)
{
	t_list      *tmp;
	
	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
	}
}

void			rotate(t_list **list)
{
	t_list      *tmp;
	t_list		*ptr;

	if (*list && (*list)->next)
	{
		tmp = *list;
		*list = (*list)->next;
		ptr = *list;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = tmp;
		tmp->next = NULL;
	}
}
void			rrotate(t_list **list)
{
	t_list		*tmp;
	t_list		*ptr;

	if (*list && (*list)->next)
	{
		ptr = *list;
		while (ptr->next->next)
			ptr = ptr->next;
		tmp = ptr->next;
		ptr->next = NULL;
		tmp->next = *list;
		*list = tmp;
	}
}

void ps_move(t_tower *tower, enum e_move move)
{
	ft_lst_pushback(&(tower->moves), &(move), sizeof(move));
	if (move == sa)
		swap(&tower->a);
	else if (move == sb)
		swap(&tower->b);
	else if (move == ss)
	{
		swap(&tower->a);
		swap(&tower->b);
	}
	else if (move == pa)
		push(&tower->b, &tower->a);
	else if (move == pb)
		push(&tower->a, &tower->b);
	else if (move == ra)
		rotate(&tower->a);
	else if (move == rb)
		rotate(&tower->b);
	else if (move == rr)
	{
		rotate(&tower->a);
		rotate(&tower->b);
	}
	else if (move == rra)
		rrotate(&tower->a);
	else if (move == rrb)
		rrotate(&tower->b);
	else if (move == rrr)
	{
		rrotate(&tower->a);
		rrotate(&tower->b);
	}
	if (tower->debug == 1)
		print_debug(tower, move);
}