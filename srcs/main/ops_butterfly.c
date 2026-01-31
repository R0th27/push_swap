/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:10:59 by htoe              #+#    #+#             */
/*   Updated: 2026/02/01 01:17:50 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	float_max(t_psstack *b, int max, int max_pos, int pos)
{
	t_psnode	*head;

	head = b -> top;
	max = head -> index;
	while (head)
	{
		if (head -> index > max)
		{
			max = head -> index;
			max_pos = pos;
		}
		head = head -> next;
		pos++;
	}
	if (max_pos <= b -> size / 2)
	{
		while (b -> top -> index != max)
			ops_rb(b, 0);
	}
	else
	{
		while (b -> top -> index != max)
			ops_rrb(b, 0);
	}
}

void	butter_fly(t_psstack *a, t_psstack *b, int counter, int chunk)
{
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
	while (b -> size > 0)
	{
		float_max(b, 0, 0, 0);
		ops_pa(b, a, 0);
	}
}
