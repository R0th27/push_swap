/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initiator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 21:17:34 by htoe              #+#    #+#             */
/*   Updated: 2026/01/30 03:24:07 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_error	add_ps_node(int num, t_psnode **head)
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

t_error	stacks_initialize(t_psstack **a, t_psstack **b, t_psnode *head)
{
	*a = (t_psstack *)malloc(sizeof(t_psstack));
	if (!*a)
		return (ERR_MALLOC);
	*b = (t_psstack *)malloc(sizeof(t_psstack));
	if (!b)
		return (ERR_MALLOC);
	(*b)-> top = NULL;
	(*b)-> bottom = NULL;
	(*b)-> size = 0;
	(*a)-> top = head;
	(*a)-> size = 1;
	while (head -> next)
	{
		((*a)-> size)++;
		head = head -> next;
	}
	(*a)-> bottom = head;
	if ((*a)-> size == 1)
		return (ERR_ONE_INPUT);
	return (ERR_OK);
}
