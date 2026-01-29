/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:59:43 by htoe              #+#    #+#             */
/*   Updated: 2026/01/29 21:00:15 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	handle_error(t_error err)
{
	if (err != ERR_OK)
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
		j = 0;
		if (av[i][j] == '+' || av[i][j] == '-')
			j++;
		if (!av[i][j])
			return (ERR_INVALID_INPUT);
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (ERR_INVALID_INPUT);
			j++;
		}
		if (j > 11)
			return (ERR_OVERFLOW_POTENTIAL);
	}
	return (ERR_OK);
}

int	ps_atoi_strict(char *str, t_error *err)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		sign = 44 - str[i++];
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	if ((sign == 1 && num > INT_MAX) || (sign == -1 && -(num) < INT_MIN))
		*err = ERR_OVERFLOW_INPUT;
	else
		*err = ERR_OK;
	return (sign * num);
}

t_error	parse_input(int ac, char **av, t_psnode **head)
{
	int		i;
	int		num;
	t_error	err;

	i = 0;
	while (++i < ac)
	{
		num = ps_atoi_strict(av[i], &err);
		if (err != ERR_OK)
			return (err);
		printf("num: %d\n", num);
	}
	(void)head;
	return (ERR_OK);
}
