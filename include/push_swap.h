/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:36:15 by htoe              #+#    #+#             */
/*   Updated: 2026/01/28 19:05:47 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef enum e_error
{
	ERR_OK,
	ERR_INVALID_INPUT,
	ERR_OVERFLOW_INPUT,
	ERR_DUPLICATE_INPUT,
	ERR_MALLOC,
	ERR_SORTED,
}	t_error;

typedef struct s_psnode
{
	int				val;
	int				index;
	struct s_psnode	*next;
}	t_psnode;

typedef struct s_psstack
{
	struct s_psnode	*top;
	struct s_psnode	*bottom;
	int				size;	
}	t_psstack;

//input_check_parse_check
t_error		input_check1(int ac, char **av);
t_error		parse_input(int ac, char **av, t_psnode **head);

//error_handling
void		handle_error(t_error err);

#endif
