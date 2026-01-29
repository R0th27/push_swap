/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:36:15 by htoe              #+#    #+#             */
/*   Updated: 2026/01/30 03:52:19 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
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
t_error		process_input2(char *str, t_psnode **head);
int			ps_atoi_strict(char *str, t_error *err);

//create+free nodes and stacks;
t_error		add_ps_node(int num, t_psnode **head);
t_error		stacks_initialize(t_psstack **a, t_psstack **b, t_psnode *head);
void		free_ps_node(t_psnode **head);
void		free_ps_split(char **arr);

//duplicate+alredy sorted checking and indexing;
t_error		indexing_list(t_psstack *a, t_psnode *head);
int			check_sorted(t_psnode *head);

//Centralized Error Handling;
void		handle_error(t_error err);

//testing
void		print_list(t_psnode *head);
void		print_stack(t_psstack *a, t_psstack *b);

#endif
