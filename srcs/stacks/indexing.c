/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 03:42:42 by htoe              #+#    #+#             */
/*   Updated: 2026/01/30 10:49:09 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	ps_merge(void **ptr1, void **ptr2, int left, int right)
{
	int		i;
	int		j;
	int		index;
	void	**temp;

	temp = (void **)malloc(sizeof(void *) * (left + right));
	if (!temp)
		return ;
	i = 0;
	j = 0;
	index = 0;
	while (i < left && j < right)
	{
		if (((t_psnode *)ptr1[i])->val <= ((t_psnode *)ptr2[j])->val)
			temp[index++] = ptr1[i++];
		else
			temp[index++] = ptr2[j++];
	}
	while (i < left)
		temp[index++] = ptr1[i++];
	while (j < right)
		temp[index++] = ptr2[j++];
	while (index--)
		ptr1[index] = temp[index];
	free(temp);
}

static void	ps_merge_sort(void **ptr, int size)
{
	int	mid;

	if (size <= 1)
		return ;
	mid = size / 2;
	ps_merge_sort(ptr, mid);
	ps_merge_sort(ptr + mid, size - mid);
	ps_merge(ptr, ptr + mid, mid, size - mid);
}

static t_error	ps_put_index(void **ptr, int size)
{
	int			i;
	t_psnode	*current;
	t_psnode	*next;

	i = -1;
	while (++i < size)
	{
		current = (t_psnode *)ptr[i];
		current -> index = i;
	}
	i = -1;
	while (++i < size - 1)
	{
		current = (t_psnode *)ptr[i];
		next = (t_psnode *)ptr[i + 1];
		if (current -> val == next -> val)
			return (ERR_DUPLICATE_INPUT);
	}
	return (ERR_OK);
}

t_error	indexing_list(t_psstack *a, t_psnode *head)
{
	void		**ptr;
	int			i;
	t_error		err;

	if (check_sorted(head))
		return (ERR_SORTED);
	ptr = (void **)malloc(sizeof(void *) * a -> size);
	if (!ptr)
		return (ERR_MALLOC);
	i = -1;
	while (++i < a -> size)
	{
		ptr[i] = head;
		head = head -> next;
	}
	ps_merge_sort(ptr, a -> size);
	err = ps_put_index(ptr, a -> size);
	free(ptr);
	return (err);
}
