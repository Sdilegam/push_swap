/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_manda_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 08:18:19 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/24 13:47:10 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

t_stack	*copy_stack(t_stack *stack_from)
{
	t_stack	*new_stack;
	int		index;

	index = -1;
	new_stack = malloc(sizeof(t_stack) * 2);
	if (!new_stack)
		return (NULL);
	new_stack[0].stack = malloc(sizeof(int) * stack_from[0].length);
	if (!new_stack[0].stack)
		return (NULL);
	new_stack[1].stack = malloc(sizeof(int) * stack_from[1].length);
	if (!new_stack[1].stack)
		return (NULL);
	new_stack[0].length = stack_from[0].length;
	new_stack[1].length = stack_from[1].length;
	while (++index < stack_from[0].length)
		new_stack[0].stack[index] = stack_from[0].stack[index];
	index = -1;
	while (++index < stack_from[1].length)
		new_stack[1].stack[index] = stack_from[1].stack[index];
	return (new_stack);
}

int	is_sorted(t_stack stack)
{
	int	index;
	int	smallest_index;

	smallest_index = get_index(stack, get_smallest(stack)) - 1;
	index = smallest_index;
	while (++index < stack.length - 1)
	{
		if (stack.stack[index] > stack.stack[index + 1])
			return (0);
	}
	if (smallest_index != -1)
	{
		if (stack.stack[index] > stack.stack[0])
			return (0);
		index = -1;
		while (++index < smallest_index)
		{
			if (stack.stack[index] > stack.stack[index + 1])
				return (0);
		}
	}
	return (1);
}

int	abs(int i)
{
	if (i >= 0)
		return (i);
	else
		return (-i);
}

t_functions	get_functions(int id)
{
	t_functions	f;

	if (id == 0)
	{
		f.push = &push;
		f.rotate = &rotate;
		f.rev_rotate = &rev_rotate;
		f.rotate_both = &rotate_both;
	}
	else
	{
		f.push = &print_push;
		f.rotate = &print_rotate;
		f.rev_rotate = &print_rev_rotate;
		f.rotate_both = &print_rotate_both;
	}
	return (f);
}
