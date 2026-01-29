/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:59:43 by htoe              #+#    #+#             */
/*   Updated: 2026/01/30 01:43:30 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	handle_error(t_error err)
{
	if (err == ERR_INVALID_INPUT)
		ft_putstr_fd("Invalid input\n", 2);
	else if (err == ERR_OVERFLOW_INPUT)
		ft_putstr_fd("Overflow int\n", 2);
	if (err != ERR_OK)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

int	ps_atoi_strict(char *str, t_error *err)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		sign = 44 - str[i++];
	if (!str[i])
		return (*err = ERR_INVALID_INPUT, 0);
	num = 0;
	while (str[i])
	{
		if (i > 11)
			return (*err = ERR_OVERFLOW_INPUT, 0);
		else if (!ft_isdigit(str[i]))
			return (*err = ERR_INVALID_INPUT, 0);
		num = (num * 10) + (str[i++] - '0');
	}
	if ((sign == 1 && num > INT_MAX) || (sign == -1 && -(num) < INT_MAX))
		return (*err = ERR_OVERFLOW_INPUT, 0);
	*err = ERR_OK;
	return (sign * num);
}

t_error	process_input(int ac, char **av, t_psnode **head)
{
	int		i;
	int		num;
	t_error	err;

	//if (ac == 2)
	//	return (process_input2(av));
	err = ERR_OK;
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