/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:39:40 by htoe              #+#    #+#             */
/*   Updated: 2026/02/01 01:17:55 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	handle_error(t_error err)
{
	if (err != ERR_OK && err != ERR_SORTED && err != ERR_ONE_INPUT)
		ft_putstr_fd("Error\n", 2);
	if (err == ERR_INVALID_INPUT || err == ERR_OVERFLOW_INPUT)
		exit(1);
}

void	push_swap(t_psstack *a, t_psstack *b)
{
	int	i;
	int	chunk;

	i = 1;
	while (i <= a -> size / i)
		i++;
	chunk = i * 1.6;
	if (a -> size > 5)
		butter_fly(a, b, 0, chunk);
	else
		small_sort(a, b, a -> size);
}

int	main(int ac, char **av)
{
	t_psnode	*head;
	t_psstack	*a;
	t_psstack	*b;
	t_error		err;

	if (ac < 2)
		exit(1);
	a = NULL;
	b = NULL;
	head = NULL;
	err = process_input(ac, av, &head);
	if (err == ERR_OK)
		err = stacks_initialize(&a, &b, head);
	if (err == ERR_OK)
		err = indexing_list(a, head);
	if (err == ERR_OK)
		push_swap(a, b);
	if (err != ERR_OK)
		handle_error(err);
	head = a -> top;
	return (free_ps_node(&head), free(a), free(b), 0);
}
