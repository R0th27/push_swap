/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:58:54 by htoe              #+#    #+#             */
/*   Updated: 2026/01/30 22:03:44 by htoe             ###   ########.fr       */
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

static t_error	apply_instruction(t_psstack *a, t_psstack *b,
	char *ops, size_t len)
{
	if (!ft_strncmp("sa", ops, len))
		ops_sa(a, 1);
	else if (!ft_strncmp("sb", ops, len))
		ops_sb(b, 1);
	else if (!ft_strncmp("ss", ops, len))
		ops_ss(a, b, 1);
	else if (!ft_strncmp("ra", ops, len))
		ops_ra(a, 1);
	else if (!ft_strncmp("rb", ops, len))
		ops_rb(b, 1);
	else if (!ft_strncmp("rr", ops, len))
		ops_rr(a, b, 1);
	else if (!ft_strncmp("rra", ops, len))
		ops_rra(a, 1);
	else if (!ft_strncmp("rrb", ops, len))
		ops_rrb(b, 1);
	else if (!ft_strncmp("rrr", ops, len))
		ops_rrr(a, b, 1);
	else if (!ft_strncmp("pa", ops, len))
		ops_pa(b, a, 1);
	else if (!ft_strncmp("pb", ops, len))
		ops_pb(a, b, 1);
	else
		return (ERR_INVALID_OPS);
	return (ERR_OK);
}

static t_error	stdin_instruction(t_psstack *a, t_psstack *b)
{
	char	*line;
	char	*instruction;
	size_t	len;
	t_error	err;

	line = get_next_line(0);
	while (line)
	{
		instruction = ft_strtrim(line, "\n ");
		if (!instruction)
			return (free(line), ERR_MALLOC);
		free(line);
		len = ft_strlen(instruction) + 1;
		err = apply_instruction(a, b, instruction, len);
		free(instruction);
		if (err != ERR_OK)
			return (ERR_INVALID_OPS);
		line = get_next_line(0);
	}
	return (ERR_OK);
}

static void	check_condition(t_psstack *a, t_psstack *b)
{
	if (check_sorted(a -> top) && !(b -> size))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char **av)
{
	t_psnode	*head;
	t_psstack	*a;
	t_psstack	*b;
	t_error		err;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	head = NULL;
	err = process_input(ac, av, &head);
	if (err == ERR_OK)
		err = stacks_initialize(&a, &b, head);
	if (err == ERR_OK)
		err = stdin_instruction(a, b);
	if (err != ERR_OK)
		handle_error(err);
	head = a -> top;
	check_condition(a, b);
	return (free_ps_node(&head), free(a), free(b), 0);
}
