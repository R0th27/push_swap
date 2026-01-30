/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 06:25:56 by htoe              #+#    #+#             */
/*   Updated: 2026/01/30 08:05:22 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	push_swap(t_psstack *a, t_psstack *b)
{
	(void)b;
	print_list(a -> top);
	print_list(b -> top);
	ops_pb(a, b, 0);
	print_list(a -> top);
	print_list(b -> top);
	ops_pb(a, b, 0);
	print_list(a -> top);
	print_list(b -> top);
	ops_pb(a, b, 0);
	print_list(a -> top);
	print_list(b -> top);
}
