/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 06:28:16 by htoe              #+#    #+#             */
/*   Updated: 2026/02/02 07:37:32 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	swap_top(t_psstack *x)
{
	t_psnode	*node1;
	t_psnode	*node2;
	t_psnode	*node3;

	if (x -> size < 2)
		return ;
	node1 = x -> top;
	node2 = node1 -> next;
	node3 = node2 -> next;
	node2 -> prev = NULL;
	node2 -> next = node1;
	node1 -> prev = node2;
	node1 -> next = node3;
	if (node3)
		node3 -> prev = node1;
	else
		x -> bottom = node1;
	x -> top = node2;
}

void	ops_sa(t_psstack *a, int silent)
{
	swap_top(a);
	if (!silent)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	ops_sb(t_psstack *b, int silent)
{
	swap_top(b);
	if (!silent)
		ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	ops_ss(t_psstack *a, t_psstack *b, int silent)
{
	ops_sa(a, 1);
	ops_sb(b, 1);
	if (!silent)
		ft_putstr_fd("ss\n", STDOUT_FILENO);
}
