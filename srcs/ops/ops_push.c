/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 07:10:32 by htoe              #+#    #+#             */
/*   Updated: 2026/01/30 11:30:11 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	push(t_psstack *from, t_psstack *to)
{
	t_psnode	*node;

	if (from -> size == 0)
		return ;
	node = from -> top;
	from -> top = from -> top -> next;
	if (from -> top)
		from -> top -> prev = NULL;
	else
		from -> bottom = NULL;
	from -> size--;
	node -> prev = NULL;
	node -> next = to -> top;
	if (to -> top)
		to -> top -> prev = node;
	else
		to -> bottom = node;
	to -> top = node;
	to -> size++;
}

void	ops_pa(t_psstack *from, t_psstack *to, int silent)
{
	push(from, to);
	if (!silent)
		ft_putstr_fd("pa\n", 1);
}

void	ops_pb(t_psstack *from, t_psstack *to, int silent)
{
	push(from, to);
	if (!silent)
		ft_putstr_fd("pb\n", 1);
}
