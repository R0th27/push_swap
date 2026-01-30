/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:10:59 by htoe              #+#    #+#             */
/*   Updated: 2026/01/30 13:25:54 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	float_max(t_psstack *b)
{
	t_psnode	*head;
	int			pos;

	pos = 0;
	head = b -> top;
	while (head && head -> index != b -> size - 1)
	{
		pos++;
		head = head -> next;
	}
	if (pos <= b -> size / 2)
	{
		while (b -> top -> index != b -> size - 1)
			ops_rb(b, 0);
	}
	else
	{
		while (b -> top -> index != b -> size - 1)
			ops_rrb(b, 0);
	}
}

static void	push_swap2(t_psstack *a, t_psstack *b)
{
	while (b -> size > 0)
	{
		float_max(b);
		ops_pa(b, a, 0);
	}
}

void	push_swap(t_psstack *a, t_psstack *b)
{
	int	chunk;
	int	counter;

	chunk = 15;
	if (a -> size > 110)
		chunk = 30;
	counter = 0;
	while (a -> size > 0)
	{
		if (a -> top -> index <= counter)
		{
			ops_pb(a, b, 0);
			ops_rb(b, 0);
			counter++;
		}
		else if (a -> top -> index <= counter + chunk)
		{
			ops_pb(a, b, 0);
			counter++;
		}
		else
			ops_ra(a, 0);
	}
	push_swap2(a, b);
}
