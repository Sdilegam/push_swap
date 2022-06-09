/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:38:27 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/09 19:35:54 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

t_bool	check_item_in(int index, t_stack stack)
{
	int	i;
	int	*list;
	int	start;
	int	number;

	list = stack.stack;
	number = -1;
	i = -1;
	start = get_index(stack, stack.lim.first);
	while (start + ++i != index)
	{
		if (list[index] < list[start + i])
			return (FALSE);
		if (start + i == stack.length - 1)
		{
			start = 0;
			i = -1;
		}
	}
	return (TRUE);
}

t_bool	check_item_out(int number, int index, t_stack stack)
{
	int	*list;

	list = stack.stack;
	if ((number > stack.lim.last || number < stack.lim.first) && \
	index == get_index(stack, stack.lim.first))
		return (TRUE);
	if (index == 0)
	{
		if (list[index] < number || number < list[stack.length - 1])
			return (FALSE);
	}
	else
		if (list[index] < number || number < list[index - 1])
			return (FALSE);
	return (TRUE);
}

int	empty_b(t_stack *stacks, t_functions f)
{
	int		steps;
	t_moves	moves;

	steps = 0;
	stacks[0].lim.first = get_smallest(stacks[0]);
	stacks[0].lim.last = get_biggest(stacks[0]);
	while (stacks[1].length != 0)
	{	
		steps += move_to(get_next_change(stacks), stacks, f);
		steps += f.push(stacks, 0);
	}
	moves.a = get_index(stacks[0], get_smallest(stacks[0]));
	moves.b = 0;
	if (moves.a > stacks[0].length / 2)
		moves.a = -stacks[0].length + moves.a;
	steps += move_to(moves, stacks, f);
	return (steps);
}

int	sort(t_stack *stacks, t_functions f)
{
	int	steps;

	steps = 0;
	stacks[0].lim.first = stacks[0].stack[0];
	stacks[0].lim.last = stacks[0].stack[stacks[0].length - 1];
	while (!is_sorted(stacks[0]))
	{
		swap(stacks, 0);
		if (check_item_in(0, stacks[0]) == 0 && !is_sorted(stacks[0]))
			swap(stacks, 0);
		else
		{
			steps ++;
			if (f.rotate == &print_rotate)
				ft_printf("sa\n");
		}
		while (check_item_in(0, stacks[0]) == 0 && \
		!is_sorted(stacks[0]))
			steps += f.push(stacks, 1);
		if (check_item_in(0, stacks[0]) == 1 \
		&& !is_sorted(stacks[0]))
				steps += f.rotate(stacks, 0);
	}
	steps += empty_b(stacks, f);
	return (steps);
}
