/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:33:46 by juwong            #+#    #+#             */
/*   Updated: 2018/09/21 23:18:48 by juwong           ###   ########.fr       */
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
	int     len;
	int     pivot;
	int		index;
	int		i;
	t_list	*l;

	len = ft_lst_len(tower->a);
	index = len / ft_sqroot(len) * 2;
	while (len > 2)
	{
		i = index;
		l = sort_list(tower->a);
		pivot = find_pivot_value(l, index);
		ft_lstdel(&l, ft_freecontent);
		while (i >= 1 && tower->a)
		{
			if (*(int*)tower->a->content <= pivot)
			{	
				ps_move(tower, pb);
				i--;
				len--;
			}
			else
				ps_move(tower, ra);
		}
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
	while (list)
	{
		if ((equality == '>' && (pivot >= *(int*)list->content)) ||
			((equality == '<') && (pivot <= *(int*)list->content)))
		{
			if (ft_abs(shortest) < ft_abs(find_distance(i, len)))
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

	while (tower->b)
	{
		qty = 2;
	while (qty > 0 && tower->b)
	{
		pivot = get_pivot(qty, 1, tower->b);
		direction = get_direction(tower->b, pivot, '>');
		while (*(int*)tower->b->content < pivot)
		{
			if (direction < 0)
				ps_move(tower, rrb);
			else
				ps_move(tower, rb);
			printf("%d \n", pivot);
		}
		qty = *(int*)tower->b->content == pivot ? 0 : qty--;
		ps_move(tower, pa);
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

	sub_size = partition_a(tower);
	if (ft_lst_len(tower->a) == 2)
		swap2(tower);
	insertion_sort(tower);
	ft_printf("size == %d\n", sub_size);
}