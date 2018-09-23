/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 21:52:47 by juwong            #+#    #+#             */
/*   Updated: 2018/09/21 21:56:21 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_tower	*tower;
	
	tower = NULL;
	if (argc < 2)
		return (0);
	ps_init_args(&tower, argc, argv);
	push_swap(tower);
	close_env(tower);
	return (0);
}

void test_sort(t_list *list)
{	
	t_list		*new;
	
	new = sort_list(list);
	print_list(list);
	print_list(new);
}

void	push_swap(t_tower *tower)
{
//	merge_sort(tower);

//	ft_printf("%d \n", get_pivot(1, 1, tower->a));
//	ft_printf("%d \n", get_pivot(3, 1, tower->a));

	start_sort(tower);
	print_list(tower->a);
	print_list(tower->b);
	print_list(tower->moves);
	ft_printf("|%d|", ft_lst_len(tower->moves));

//	test_sort(tower->a);
}