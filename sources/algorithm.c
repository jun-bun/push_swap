/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:33:46 by juwong            #+#    #+#             */
/*   Updated: 2018/09/28 23:57:12 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int     find_pivot_value(t_list *list, int index)
{
	int     len;
	t_list  *tmp;
	int		i;

	i = 1;
	len = ft_lst_len(list);
	tmp = list;
	while (i < index && tmp)
	{
		if (!tmp->next)
			return (*(int*)tmp->content);
		tmp = tmp->next;
		i++;
	}
	return (*(int*)tmp->content);
}


int		partition_a(t_tower *tower)
{
	int     pivot;
	int		index;
	int		i;
	t_list	*l;

	index = ft_sqroot(ft_lst_len(tower->a)) * 4;
	while (tower->a)
	{
		i = index;
		l = sort_list(tower->a);
		pivot = find_pivot_value(l, index);
		while (i >= 1 && tower->a)
		{
			if (*(int*)tower->a->content <= pivot)
			{
				ps_move(tower, pb);
				if (find_pivot_value(l, index / 2) > *(int*)tower->b->content)
					ps_move(tower, rb);
				i--;
			}
			else
				ps_move(tower, ra);
		}
		ft_lstdel(&l, ft_freecontent);
	}
	return (index);
}


int		find_max(t_list *list)
{
	int		max;

	max = INT_MIN;
	while (list)
	{
		if (*(int*)list->content > max)
			max = *(int*)list->content;
		list = list->next;
	}
	return (max);
}

int		get_direction(t_list *list, int pivot, char	equality)
{
	int		i;
	int		shortest;
	int		len;

	len = ft_lst_len(list);
	i = 0;
	shortest = INT_MAX;
	while (list)
	{
		if ((equality == '>' && (*(int*)list->content >= pivot)) ||
			((equality == '<') && (*(int*)list->content <= pivot)))
		{

			if (ft_abs(find_distance(i, len)) < ft_abs(shortest))
				shortest = find_distance(i, len);
		}
		list = list->next;
		i++;
	}
		return (shortest);
}

int		get_pivot(int qty, int minmax,	t_list *list)
{
		t_list	*sorted;
		t_list	*tmp;
		int		len;
		int		pivot;

		sorted = sort_list(list);
		tmp = sorted;
		if (minmax == -1)
			while (--qty >= 1)
				tmp = tmp->next;
		else
		{
			len = ft_lst_len(sorted);
			len -= qty + 1;
			while (--len >= -1)
				tmp = tmp->next;
		}
		pivot = *(int*)tmp->content;
		ft_lstdel(&sorted, ft_freecontent);
		return (pivot);
}


void	insertion_sort(t_tower *tower)
{
	int			pivot;
	int			direction;
	int			qty;
	int			split;
	int			i;

	while (tower->b)
	{
		qty = 4;
		pivot = get_pivot(qty, 1, tower->b);
		split = get_pivot(qty / 2, 1, tower->b);
		i = 1;
		while (qty > 0 && tower->b)
		{
			while (*(int*)tower->b->content < pivot)
			{
				direction = get_direction(tower->b, pivot, '>');
				if (direction < 0)
					ps_move(tower, rrb);
				else
					ps_move(tower, rb);
			}
			qty = *(int*)tower->b->content == get_max(tower->b, INT_MAX) ? 0 : --qty;
			ps_move(tower, pa);
			if (*(int*)tower->a->content < split)
			{
				ps_move(tower, ra);
				i++;
			}
			sort2(tower);
		}
		while (--i)
			{
				ps_move(tower, rra);
				sort2(tower);
			}
	}
}

void swap2(t_tower *tower)
{
	if (*(int*)tower->a->content > *(int*)tower->a->next->content)
	{
		if (*(int*)tower->b->content < *(int*)tower->b->next->content)
			ps_move(tower, ss);
		else
			ps_move(tower, sa);
	}
	else if (*(int*)tower->b->content < *(int*)tower->b->next->content)
		ps_move(tower, sb);
}

void    start_sort(t_tower *tower)
{
	int		sub_size;

	if (ft_lst_len(tower->a) <= 16)
		sortsmall(tower);
	else
	{
		sub_size = partition_a(tower);
		if (ft_lst_len(tower->a) == 2)
		sort3(tower);
		insertion_sort(tower);
	}
}