/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 21:52:47 by juwong            #+#    #+#             */
/*   Updated: 2018/09/28 19:52:18 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		handle_moves(t_tower *tower, char *line)
{
	if (ft_strequ(line, "sa"))
		ps_move(tower, sa);
	else if (ft_strequ(line, "sb"))
		ps_move(tower, sb);
	else if (ft_strequ(line, "ss"))
		ps_move(tower, ss);
	else if (ft_strequ(line, "pa"))
		ps_move(tower, pa);
	else if (ft_strequ(line, "pb"))
		ps_move(tower, pb);
	else if (ft_strequ(line, "ra"))
		ps_move(tower, ra);
	else if (ft_strequ(line, "rb"))
		ps_move(tower, rb);
	else if (ft_strequ(line, "rr"))
		ps_move(tower, rr);
	else if (ft_strequ(line, "rra"))
		ps_move(tower, rra);
	else if (ft_strequ(line, "rrb"))
		ps_move(tower, rrb);
	else if (ft_strequ(line, "rrr"))
		ps_move(tower, rrr);
	else
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_tower *tower;
	char	*line;

	tower = NULL;
	if (argc < 2)
		return (0);
	ps_init_args(&tower, argc, argv);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strequ(line, ""))
			break ;
		if (handle_moves(tower, line))
		{
			ft_printf("Error\n");
			free(line);
			close_env(tower);
			exit(1);
		}
		free(line);
	}
	if (issort(tower))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	close_env(tower);
	return (0);
}