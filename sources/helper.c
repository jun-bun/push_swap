/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 21:01:28 by juwong            #+#    #+#             */
/*   Updated: 2018/09/28 22:07:15 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int     issort(t_tower *tower)
{
	t_list      *tmp;

	tmp = tower->a;
	if (tower->b)
		return (0);
	while (tmp)
	{
		if (*(int*)tmp->content > *(int*)tmp->next->content)
			return (0);
		tmp = tmp->next;
		if (!tmp->next)
			break;
	}
	return (1);
}

int		isascending(t_list *list)
{
	t_list		*tmp;
	
	tmp = list;
	while (tmp && tmp->next)
	{
		if (*(int*)tmp->content > *(int*)tmp->next->content)
			return (0);
		tmp = tmp->next;
		if (!tmp->next)
			break;
	}
	return (1);
}

int		isdecending(t_list *list)
{
	t_list		*tmp;
	
	tmp = list;
	while (tmp)
	{
		if (*(int*)tmp->content < *(int*)tmp->next->content)
			return (0);
		tmp = tmp->next;
		if (!tmp->next)
			break;
	}
	return (1);
}

t_min	getmin(t_list *list)
{
	t_min		min;
	int			i;

	min.a = INT_MAX;
	i = 0;
	while(list)
	{
		if (*(int*)list->content < min.a)
		{
			min.a = *(int*)list->content;
			min.a_i = i;
		}
		list = list->next;
		i++;
		if (!list)
			break;
	}
	min.len = i;
	return (min);
}

t_min	get_next_mins(t_list *list)
{
	t_min	min;
	int		i;

	min.a = INT_MAX;
	min.b = INT_MAX;
	i = 0;
	while (list)
	{
		if (*(int*)list->content < min.a)
		{
			min.b = min.a;
			min.b_i = min.a_i;
			min.a = *(int*)list->content;
			min.a_i = i;
		}
		else if (*(int*)list->content < min.b)
		{
			min.b = *(int*)list->content;
			min.b_i = i;
		}
		i++;
		if (!list->next)
			break;
		list = list->next;
	}
	min.len = i;
	return (min);
}

int		find_distance(int point, int len)
{
	if (point <= len / 2)
		return (point);
	else
		return (point - len - 1);
}

int		get_index(t_list *list, int num)
{
	int		i;

	i = 0;
	while (list)
	{
		i++;
		if (*(int*)list->content == num)
			break;
		list = list->next;
	}
	return (i);
}

int		get_max(t_list	*list, int	len)
{	
	int		max = INT_MIN;
	
	while (list && len)
	{
		if (*(int*)list->content < max)
			max = *(int*)list->content;
		list = list->next;
		len--;
	}
	return (max);
}
/*
enum e_move	get_direction(int	num, t_list	*list)
{
	int		len;
	int		i;

	len = ft_lst_len (list);

	while (list)
	{
		if (num == *(int*)list->content)
			return (i);
		list = list->next;
	}
}
*/