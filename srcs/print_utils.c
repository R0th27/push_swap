/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 21:44:10 by htoe              #+#    #+#             */
/*   Updated: 2026/01/29 21:53:02 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	print_list(t_psnode *head)
{
	if (!head)
		return ;
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
}
