/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 07:13:27 by htoe              #+#    #+#             */
/*   Updated: 2026/01/30 07:52:58 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	rotate(t_psstack *x)
{
	t_psnode	*old_top;

	if (x -> size < 2)
		return ;
	old_top = x -> top;
	x -> top = x -> top -> next;
	x -> top -> prev = NULL;
	old_top -> prev = x -> bottom;
	x -> bottom -> next = old_top;
	x -> bottom = old_top;
	old_top -> next = NULL;
}

void	ops_ra(t_psstack *a, int silent)
{
	rotate(a);
	if (!silent)
		ft_putstr_fd("ra\n", 1);
}

void	ops_rb(t_psstack *b, int silent)
{
	rotate(b);
	if (!silent)
		ft_putstr_fd("rb\n", 1);
}

void	ops_rr(t_psstack *a, t_psstack *b, int silent)
{
	ops_ra(a, 1);
	ops_rb(b, 1);
	if (!silent)
		ft_putstr_fd("rr\n", 1);
}
