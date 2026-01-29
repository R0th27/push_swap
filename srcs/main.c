/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:39:40 by htoe              #+#    #+#             */
/*   Updated: 2026/01/30 01:25:48 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_psnode	*head;
	t_psstack	*a;
	t_error		err;

	if (ac < 2)
		exit(1);
	err = process_input(ac, av, &head);
	if (err != ERR_OK)
		handle_error(err);
	(void)a;
	ft_printf("SUCCESS\n");
	return (0);
}
