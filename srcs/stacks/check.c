/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:36:26 by htoe              #+#    #+#             */
/*   Updated: 2026/01/30 10:36:34 by htoe             ###   ########.fr       */
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
