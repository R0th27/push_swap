/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:36:39 by htoe              #+#    #+#             */
/*   Updated: 2026/01/28 19:06:51 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	handle_error(t_error err)
{
	if (err == ERR_INVALID_INPUT)
		ft_putstr_fd("Error\n", 2);
	exit(1);
}

t_error	input_check1(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				if (j != 0)
					return (ERR_INVALID_INPUT);
				else if (av[i][j] != '+' && av[i][j] != '-')
					return (ERR_INVALID_INPUT);
				else if (!ft_isdigit(av[i][j + 1]))
					return (ERR_INVALID_INPUT);
			}
		}
	}
	return (ERR_OK);
}
