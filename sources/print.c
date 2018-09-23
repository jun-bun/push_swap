/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:18:03 by juwong            #+#    #+#             */
/*   Updated: 2018/09/18 17:22:25 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	get_list_colors(enum e_move move, char **color_a, char **color_b)
{
		if (move == sa || move == ss)
			*color_a = RED;
		if (move == sb || move == ss)
			*color_b = RED;
		if (move == pa)
			*color_b = GREEN;
		if (move == pb)
			*color_a = GREEN;
		if (move == ra || move == rr)
			*color_a = BLUE;
		if (move == rb || move == rr)
			*color_b = BLUE;
		if (move == rra || move == rrr)
			*color_a = YELLOW;
		if (move == rrb || move == rrr)
			*color_b = YELLOW;
}

void 		print_list(t_list *list)
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

void		print_debug(t_tower *tower, enum e_move move)
{
		static char	*color_a;
		static char	*color_b;

		color_a = WHITE;
		color_b = WHITE;
		if (tower->color == 1)
			get_list_colors(move, &color_a, &color_b);
		ft_printf("STACK A | ");
		if (tower->printlen)
			ft_printf("%d | ", ft_lst_len(tower->a));
		ft_printf(color_a);
		print_list(tower->a);
		ft_printf(END);
		ft_printf("STACK B | ");
		if (tower->printlen)
			ft_printf("%d | ", ft_lst_len(tower->b));
		ft_printf(color_b);
		print_list(tower->b);
		ft_printf(END);
		if (tower->printmove)
			ft_printf("Move # %d", ft_lst_len(tower->moves));
		ft_printf("\n\n");
}
