/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 23:25:39 by juwong            #+#    #+#             */
/*   Updated: 2018/09/29 00:15:31 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_tower		*init_tower(void)
{
	int			i;
	t_tower		*tower;

	i = -1;
	tower = (t_tower*)malloc(sizeof(t_tower));	
	tower->moves = NULL;
	tower->b = NULL;
	tower->a = NULL;
	tower->debug = 0;
	tower->color = 0;
	tower->printsort = 0;
	tower->printlen = 0;
	tower->printmove = 0;
	return (tower);
}

int			valid_nbr(int i, char **argv, t_list *list)
{
	int		x;
	long	tmp;

	x = -1;
	while (argv[i][++x])
	{
		if ((!ft_isdigit(argv[i][x])) && !(argv[i][x] == '-' && x == 0))
			return (0);
	}
	if (x > 11)
		return (0);
	if (x == 0)
		return (0);
	tmp = ft_atol(argv[i]);
	if (tmp > INT_MAX || tmp < INT_MIN)
		return (0);
	if (i != 0 && isdupe(list, (int)tmp))
		return (0);
	return (1);
}

int		handle_options(int i, char **argv, t_tower **tower)
{
	while (argv[i])
	{
		if (ft_strequ(argv[i], "-d"))
			(*tower)->debug = 1;
		else if (ft_strequ(argv[i], "-c"))
			(*tower)->color = 1;
		else if (ft_strequ(argv[i], "-m"))
			(*tower)->printmove = 1;
		else if (ft_strequ(argv[i], "-l"))
			(*tower)->printlen = 1;
		else
			break;
		i++;
	}
	return (i);
}

int			ps_init_args(t_tower **tower, int argc, char **argv)
{
	int		i;
	int		tmp;

	i = 0;
	*tower = init_tower();
	while (++i < argc)
	{
		if (!argv[i][0])
		{
			close_env(*tower);
			exit (1);
		}
		if (i == 1)
			i = handle_options(i, argv, tower);
		if (!valid_nbr(i, argv, (*tower)->a))
		{
			ft_putstr_fd("Error\n", 2);
			close_env(*tower);
			exit (1);
		}
		tmp = ft_atoi(argv[i]);
		ft_lst_pushback((t_list**)&(*tower)->a, &tmp, sizeof(int));
	}
	return (1);
}

void		close_env(t_tower *tower)
{
	if (tower->a)
		ft_lstdel(&tower->a, ft_freecontent);
	if (tower->b)
		ft_lstdel(&tower->b, ft_freecontent);
	if (tower->moves)
		ft_lstdel(&tower->moves, ft_freecontent);
	free(tower);
	exit (1);
}