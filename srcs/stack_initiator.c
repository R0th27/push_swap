/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initiator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 21:17:34 by htoe              #+#    #+#             */
/*   Updated: 2026/01/30 01:20:16 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_error	add_psnode(int num, t_psnode **head)
{
	t_psnode	*node;
	t_psnode	*tail;

	node = (t_psnode *)malloc(sizeof(t_psnode));
	if (!node)
		return (ERR_MALLOC);
	node -> val = num;
	node -> index = -1;
	node -> next = NULL;
	node -> prev = NULL;
	if (*head == NULL)
	{
		*head = node;
		return (ERR_OK);
	}
	tail = *head;
	while (tail -> next)
		tail = tail -> next;
	tail -> next = node;
	node -> prev = tail;
	return (ERR_OK);
}
