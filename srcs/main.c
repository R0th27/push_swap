/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:39:40 by htoe              #+#    #+#             */
/*   Updated: 2026/01/29 20:02:08 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_psnode	*head;
	t_psstack	*a;
	t_psstack	*b;
	t_error		err;

	if (ac < 2)
		exit(1);
	err = input_check1(ac, av);
	head = NULL;
	if (err == ERR_OK)
		err = parse_input(ac, av, &head);
	(void)a;
	(void)b;
	if (err != ERR_OK)
		handle_error(err);
	ft_printf("SUCCESS\n");
	return (0);
}
