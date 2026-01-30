/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 21:44:10 by htoe              #+#    #+#             */
/*   Updated: 2026/01/30 03:37:12 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	print_list(t_psnode *head)
{
	if (!head)
		return ;
	printf("############### LINKED LIST ###############\n");
	while (head)
	{
		printf("[%p]", head);
		printf("  ");
		if (!head -> prev)
			printf("         ");
		printf("[%p]", head -> prev);
		printf("  ");
		printf("[%d]", head -> val);
		printf("  ");
		printf("[%d]", head -> index);
		printf("  ");
		printf("[%p]", head -> next);
		printf("\n");
		head = head -> next;
	}
	printf("\n");
}

void	print_stack(t_psstack *a, t_psstack *b)
{
	if (!a || !b)
		return ;
	printf("############### STACK STATUS ###############\n");
	printf("STACK A\t\t\tSTACK B\n");
	printf("[%p]", a -> top);
	printf("\t");
	printf("[%p]", b -> top);
	printf("\n");
	printf("[%p]", a -> bottom);
	printf("\t");
	printf("[%p]", b -> bottom);
	printf("\n");
	printf("[%d]", a -> size);
	printf("\t\t\t");
	printf("[%d]", b -> size);
	printf("\n\n");
}
