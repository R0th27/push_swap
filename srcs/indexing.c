/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 03:42:42 by htoe              #+#    #+#             */
/*   Updated: 2026/01/30 03:49:40 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	check_sorted(t_psnode *head)
{
	while (head && head -> next)
	{
		if (head -> val > head -> next -> val)
			return (0);
		head = head -> next;
	}
	return (1);
}

t_error	indexing_list(t_psstack *a, t_psnode *head)
{
	if (check_sorted(head))
		return (ERR_SORTED);
	(void)a;
	return (ERR_OK);
}
