/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 21:38:04 by juwong            #+#    #+#             */
/*   Updated: 2018/09/21 20:50:47 by juwong           ###   ########.fr       */
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
	char			debug;
	char			color;
	char			printsort;
	char			printlen;
	char			printmove;
}					t_tower;

typedef struct		s_num
{
	int				*content;
	size_t			size;
	struct s_num	*next;
}					t_num;

typedef struct		s_min
{
	int				a;
	int				b;
	int				a_i;
	int				b_i;
	int				len;
}					t_min;

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

int 			isdupe(t_list *list, int num);
int				handle_options(int i, char **argv, t_tower **tower);
int				valid_nbr(int i, char **argv, t_list *list);

/*
** Initialization functions
*/

t_tower			*init_tower(void);
int				ps_init_args(t_tower **tower, int argc, char **argv);
void			push_swap(t_tower *tower);
void			ps_move(t_tower *tower, enum e_move);

/*
** Checker functions
*/
int				handle_moves(t_tower *tower, char *line);

/*
** Helper functions
*/
int     		issort(t_tower *tower);
int				find_distance(int point, int len);
t_min			get_next_mins(t_list *list);
t_min			getmin(t_list *list);
int				isascending(t_list *list);
int				isdecending(t_list *list);

/*
** Sort functions
*/
void			insert_list_ascending(t_list **list, t_list	*node);
t_list 			*sort_list(t_list *list);

/*
** Algorithm
*/
void    start_sort(t_tower *tower);
int		partition_a(t_tower *tower);
int     find_pivot_value(t_list *list, int index);
int		get_pivot(int qty, int minmax,	t_list *list);

/*
** Cleanup functions
*/
void			close_env(t_tower *tower);

void			merge_sort(t_tower *tower);

void			print_debug(t_tower *tower, enum e_move move);
#endif