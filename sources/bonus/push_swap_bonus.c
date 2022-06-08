/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:07:37 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/08 11:07:58 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_index.h"

t_bool	checker(t_stack *stacks)
{
	int	index;

	if (stacks[1].length != 0)
		return (FALSE);
	index = -1;
	if (stacks[0].length > 1)
	{
		while (++index < stacks[0].length - 1)
		{
			if (stacks[0].stack[index] > stacks[0].stack[index + 1])
				return (FALSE);
		}
	}
	return (TRUE);
}

t_l_list	*function_name(char *string)
{
	t_l_list	*instructions;

	if (!string)
		return (0);
	instructions = malloc(sizeof (t_l_list));
	if (!instructions)
		return (0);
	instructions->id = 0;
	instructions->move = 0;
	instructions->next = 0;
	if (!ft_strcmp("ra\n", string) || !ft_strcmp("rb\n", string))
		instructions->move = &rotate;
	else if (!ft_strcmp("rra\n", string) || !ft_strcmp("rrb\n", string))
		instructions->move = &rev_rotate;
	else if (!ft_strcmp("pa\n", string) || !ft_strcmp("pb\n", string))
		instructions->move = &push;
	else if (!ft_strcmp("sa\n", string) || !ft_strcmp("sb\n", string))
		instructions->move = &swap;
	else if (!ft_strcmp("rrr\n", string))
		instructions->move = &rev_rotate_both;
	else if (!ft_strcmp("rr\n", string))
		instructions->move = &rotate_both;
	else if (!ft_strcmp("ss\n", string))
		instructions->move = &swap_both;
	if (!ft_strcmp("rb\n", string) || !ft_strcmp("rrb\n", string) \
		|| !ft_strcmp("pb\n", string) || !ft_strcmp("sb\n", string))
		instructions->id = 1;
	return (instructions);
}

t_l_list	*read_input(void)
{
	t_l_list	*instructions;
	t_l_list	**cursor;
	char		*buf;

	buf = get_next_line(0);
	instructions = function_name(buf);
	cursor = &instructions;
	if (!instructions)
		free_and_exit((void **)&buf);
	while (buf && ft_strcmp(buf, "\n") && ft_strcmp(buf, ""))
	{
		ft_free_ptr((void **)&buf);
		buf = get_next_line(0);
		(*cursor)->next = function_name(buf);
		if (!(*cursor)->next)
		{
			ft_free_ptr((void **)&buf);
			free_list(instructions);
			error();
		}
		cursor = &((*cursor)->next);
	}
	ft_free_ptr((void **)&buf);
	// *cursor = 0;
	return (instructions);
}

int	main(int argc, char *argv[])
{
	t_stack		*stacks;
	t_l_list	*moves;
	t_l_list	*cursor;

	are_parameters_ok(argc, argv);
	stacks = stacks_init(argc - 1, argv);
moves = read_input();
	stacks->lim.first = stacks->stack[0];
	stacks->lim.last = stacks->stack[stacks->length - 1];
	cursor = moves;
	while (cursor->move)
	{
		cursor->move(stacks, cursor->id);
		cursor = cursor->next;
	}
	free_list(moves);
	if (checker(stacks) == TRUE)
	{
		ft_printf("OK\n");
		free_stacks(&stacks);
		return(0);
	}
	else
	{
		ft_printf("KO\n");
		free_stacks(&stacks);
		return(1);
	}
}
