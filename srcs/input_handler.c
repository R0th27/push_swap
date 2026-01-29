/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:59:43 by htoe              #+#    #+#             */
/*   Updated: 2026/01/30 03:45:32 by htoe             ###   ########.fr       */
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
	else if (err == ERR_DUPLICATE_INPUT)
		ft_putstr_fd("Duplicate int\n", 2);
	else if (err == ERR_ONE_INPUT)
		ft_putstr_fd("Only one input\n", 2);
	else if (err == ERR_SORTED)
		ft_putstr_fd("Sorted array\n", 2);
	if (err != ERR_OK && err != ERR_SORTED && err != ERR_ONE_INPUT)
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
		if (!ft_isdigit(str[i]))
			return (*err = ERR_INVALID_INPUT, 0);
		if (num > (LONG_MAX - str[i] - '0') / 10)
			return (*err = ERR_OVERFLOW_INPUT, 0);
		num = (num * 10) + (str[i++] - '0');
	}
	if ((sign == 1 && num > INT_MAX) || (sign == -1 && -(num) < INT_MIN))
		return (*err = ERR_OVERFLOW_INPUT, 0);
	return (*err = ERR_OK, sign * num);
}

t_error	process_input2(char *str, t_psnode **head)
{
	char	**arr;
	int		size;
	int		i;
	t_error	err;
	int		num;

	arr = ft_split(str, ' ');
	if (!arr)
		return (ERR_INVALID_INPUT);
	size = 0;
	while (arr[size])
		size++;
	err = ERR_OK;
	i = -1;
	while (++i < size)
	{
		num = ps_atoi_strict(arr[i], &err);
		if (err != ERR_OK)
			return (free_ps_split(arr), free_ps_node(head), err);
		err = add_ps_node(num, head);
		if (err != ERR_OK)
			return (free_ps_split(arr), free_ps_node(head), err);
	}
	return (free_ps_split(arr), ERR_OK);
}

t_error	process_input(int ac, char **av, t_psnode **head)
{
	int		i;
	int		num;
	t_error	err;

	if (ac == 2)
		return (process_input2(av[1], head));
	err = ERR_OK;
	i = 0;
	while (++i < ac)
	{
		num = ps_atoi_strict(av[i], &err);
		if (err != ERR_OK)
			return (free_ps_node(head), err);
		err = add_ps_node(num, head);
		if (err != ERR_OK)
			return (free_ps_node(head), err);
	}
	return (ERR_OK);
}
