/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:36:15 by htoe              #+#    #+#             */
/*   Updated: 2026/02/02 06:28:28 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef enum e_error
{
	ERR_OK,
	ERR_INVALID_INPUT,
	ERR_OVERFLOW_INPUT,
	ERR_ONE_INPUT,
	ERR_DUPLICATE_INPUT,
	ERR_SORTED,
	ERR_INVALID_OPS,
	ERR_MALLOC
}	t_error;

typedef struct s_psnode
{
	int				val;
	int				index;
	struct s_psnode	*next;
	struct s_psnode	*prev;
}	t_psnode;

typedef struct s_psstack
{
	struct s_psnode	*top;
	struct s_psnode	*bottom;
	int				size;	
}	t_psstack;

//input processing;
t_error		process_input(int ac, char **av, t_psnode **head);

//create+free nodes and stacks;
t_error		add_ps_node(int num, t_psnode **head);
t_error		stacks_initialize(t_psstack **a, t_psstack **b, t_psnode *head);
void		free_ps_node(t_psnode **head);
void		free_ps_split(char **arr);

//duplicate+alredy sorted checking and indexing;
t_error		indexing_list(t_psstack *a, t_psnode *head);
int			check_sorted(t_psnode *head);

//Algorithm
void		push_swap(t_psstack *a, t_psstack *b);
void		butter_fly(t_psstack *a, t_psstack *b, int counter, int chunk);
void		small_sort(t_psstack *a, t_psstack *b, int size);

//Ops
void		ops_sa(t_psstack *a, int silent);
void		ops_sb(t_psstack *b, int silent);
void		ops_ss(t_psstack *a, t_psstack *b, int silent);
void		ops_ra(t_psstack *a, int silent);
void		ops_rb(t_psstack *b, int silent);
void		ops_rr(t_psstack *a, t_psstack *b, int silent);
void		ops_rra(t_psstack *a, int silent);
void		ops_rrb(t_psstack *b, int silent);
void		ops_rrr(t_psstack *a, t_psstack *b, int silent);
void		ops_pa(t_psstack *from, t_psstack *to, int silent);
void		ops_pb(t_psstack *from, t_psstack *to, int silent);

#endif
