/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:07:37 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/10 14:03:14 by sdi-lega         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_stack		*stacks;
	t_l_list	*moves;
	t_l_list	*cursor;

	are_parameters_ok(argc, argv);
	stacks = stacks_init(argc - 1, argv);
	moves = read_input(stacks);
	stacks->lim.first = stacks->stack[0];
	stacks->lim.last = stacks->stack[stacks->length - 1];
	cursor = moves;
	while (cursor)
	{
		cursor->move(stacks, cursor->id);
		cursor = cursor->next;
	}
	free_list(moves);
	if (checker(stacks) == TRUE)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(&stacks);
	return (0);
}
