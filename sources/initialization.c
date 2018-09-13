/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 23:25:39 by juwong            #+#    #+#             */
/*   Updated: 2018/09/11 21:44:20 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_tower		*init_tower(int	*arr, int size)
{
	int			i;
	t_tower		*tower;

	i = -1;
	tower = (t_tower*)malloc(sizeof(t_tower));	
	tower->moves = 0;
	tower->a = NULL;
	tower->b = NULL;

	while (++i <= size)
	{
		ft_lst_pushback(&(tower->a), &(arr[i]), sizeof(int));
	}
	return (tower);
}

int			valid_nbr(int i, char **argv)
{
	int		x;
	long	tmp;

	x = -1;
	while (argv[i][++x])
	{
		if ((!ft_isdigit(argv[i][x])) && !(argv[i][x] == '-' && x == 0))
			return (0);
		if (x > 11)
			return (0);
		tmp = ft_atol(argv[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (0);			
	}
	return (1);
}

int			ps_init_args(t_tower *tower, int argc, char **argv)
{
	int		i;
	int		tmp;
	int		arr[argc];

	i = 0;
	while (++i < argc)
	{
		ft_printf("printed\n");
		if (!valid_nbr(i, argv))
			return (0);
		tmp = ft_atoi(argv[i]);
		ft_printf("1\n");
		if (i != 0 && isdupe(arr, (int)tmp, i - 1))
			return (0);
		ft_printf("2\n");
		arr[i - 1] = (int)tmp;
	}
	tower = init_tower(arr, i - 1);
	return (1);
}