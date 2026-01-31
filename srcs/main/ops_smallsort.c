/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_ssort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 01:10:35 by htoe              #+#    #+#             */
/*   Updated: 2026/02/01 01:16:16 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	float_max(t_psstack *a, int max, int max_pos, int pos)
{
	t_psnode	*head;

	head = a -> top;
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
	if (max_pos <= a -> size / 2)
	{
		while (a -> top -> index != max)
			ops_ra(a, 0);
	}
	else
	{
		while (a -> top -> index != max)
			ops_rra(a, 0);
	}
}

static void	small_sort_phase(t_psstack *a, t_psstack *b, int size, int phase)
{
	if (size <= 3)
		return ;
	if (phase == 1)
	{
		while (--size >= 3)
		{
			float_max(a, 0, 0, 0);
			ops_pb(a, b, 0);
		}
	}
	else
	{
		while (b -> size)
		{
			ops_pa(b, a, 0);
			ops_ra(a, 0);
		}
	}
}

void	small_sort(t_psstack *a, t_psstack *b, int size)
{
	if (size == 2)
		return (ops_sa(a, 0));
	if (size > 3)
		small_sort_phase(a, b, size, 1);
	if (a -> top -> index == 0 && a -> bottom -> index == 1)
	{
		ops_rra(a, 0);
		ops_sa(a, 0);
	}
	else if (a -> top -> index == 1 && a -> bottom -> index == 2)
		ops_sa(a, 0);
	else if (a -> top -> index == 1 && a -> bottom -> index == 0)
		ops_rra(a, 0);
	else if (a -> top -> index == 2 && a -> bottom -> index == 1)
		ops_ra(a, 0);
	else if (a -> top -> index == 2 && a -> bottom -> index == 0)
	{
		ops_sa(a, 0);
		ops_rra(a, 0);
	}
	if (b -> size)
		small_sort_phase(a, b, size, 2);
}
