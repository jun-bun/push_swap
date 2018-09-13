/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 21:38:04 by juwong            #+#    #+#             */
/*   Updated: 2018/09/11 20:30:51 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"
# include "ft_printf.h"

enum				e_move
{
	e_none,
	sa,
	sb,
	ss,
	pb,
	pa,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
};


typedef struct		s_tower
{
	t_list			*a;
	t_list			*b;
	t_list			*moves;
}					t_tower;

/*
void			pb(t_list *a, t_list *b);
void			pa(t_list *a, t_list *b);
void			sa(t_list *a, t_list *b);
void			sb(t_list *a, t_list *b);
void			ss(t_list *a, t_list *b);
void			ra(t_list *a, t_list *b);
void			rb(t_list *a, t_list *b);
void			rr(t_list *a, t_list *b);
void			rra(t_list *a, t_list *b);
void			rrb(t_list *a, t_list *b);
void			rrr(t_list *a, t_list *b);
*/

/*
void			pb(t_tower *tower);
void			pa(t_tower *tower);
void			sa(t_tower *tower);
void			sb(t_tower *tower);
void			ss(t_tower *tower);
void			ra(t_tower *tower);
void			rb(t_tower *tower);
void			rr(t_tower *tower);
void			rra(t_tower *tower);
void			rrb(t_tower *tower);
void			rrr(t_tower *tower);
*/

void			push(t_list **a, t_list **b);
void			swap(t_list	**list);
void			rotate(t_list **list);
void			rrotate(t_list **list);

/*
** Debug functions
*/
void			print_list(t_list *list);

/*
** Error handling
*/

int 			isdupe(int *arr, int num, int i);
int				valid_nbr(int i, char **argv);

/*
** Initialization functions
*/

t_tower			*init_tower(int	*arr, int size);
int				ps_init_args(t_tower *tower, int argc, char **argv);
void			push_swap(t_list *list);
void			ps_move(t_tower *tower, enum e_move);

/*
** Checker functions
*/
int				handle_moves(t_tower *tower, char *line);

#endif