/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 02:35:16 by htoe              #+#    #+#             */
/*   Updated: 2026/01/30 03:17:08 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	free_ps_node(t_psnode **head)
{
	t_psnode	*temp;
	t_psnode	*current;

	if (!head)
		return ;
	current = *head;
	while (current)
	{
		temp = current;
		current = current -> next;
		free(temp);
	}
	*head = NULL;
}

void	free_ps_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
