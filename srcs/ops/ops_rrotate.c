/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 07:37:08 by htoe              #+#    #+#             */
/*   Updated: 2026/02/02 07:37:21 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	rrotate(t_psstack *x)
{
	t_psnode	*old_bot;

	if (x -> size < 2)
		return ;
	old_bot = x -> bottom;
	x -> bottom = x -> bottom -> prev;
	x -> bottom -> next = NULL;
	old_bot -> next = x -> top;
	x -> top -> prev = old_bot;
	x -> top = old_bot;
	old_bot -> prev = NULL;
}

void	ops_rra(t_psstack *a, int silent)
{
	rrotate(a);
	if (!silent)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	ops_rrb(t_psstack *b, int silent)
{
	rrotate(b);
	if (!silent)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	ops_rrr(t_psstack *a, t_psstack *b, int silent)
{
	ops_rra(a, 1);
	ops_rrb(b, 1);
	if (!silent)
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
