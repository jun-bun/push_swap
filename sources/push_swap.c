/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 21:52:47 by juwong            #+#    #+#             */
/*   Updated: 2018/09/10 23:25:36 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_list	*list;
	int		num;
	int		i;

	i = 1;
	list = NULL;
	if (argc > 1)
	{
		while (i < argc)
		{
			num = ft_atoi(argv[i]);
			ft_lst_pushback(&list, &num, sizeof(int));
			list->content = list->content;
			i++;
		}
	}
	push_swap(list);
	return (1);
}

void	push_swap(t_list *list)
{
	t_tower		*tower;

	tower = init_tower(list);

//	swap(&(tower->a));
//	rotate(&(tower->a));
//	rrotate(&tower->a);
	ps_move(tower, pb);
	ps_move(tower, pb);
	ps_move(tower, sa);
	ps_move(tower, sb);
	print_list(tower->a);
	print_list(tower->b);
	print_list(tower->moves);
}

void print_list(t_list *list)
{
	t_list		*tmp;

	tmp = list;
	while (tmp)
	{
		ft_printf("|%d|", *(int*)tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
}