/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:35:01 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/29 19:35:56 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comn_index.h"

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
t_bool	get_index(t_stack stack, int item)
{
	int	index;

	index = -1;
	while (++index < stack.length)
		if (stack.stack[index] == item)
			return (index);
	return (-1);
}

int	get_smallest(t_stack stack)
{
	int	index;
	int	smallest;

	index = -1;
	smallest = stack.stack[++index];
	while (++index < stack.length)
		if (stack.stack[index] < smallest)
			smallest = stack.stack[index];
	return (smallest);
}

int	get_biggest(t_stack stack)
{
	int	index;
	int	biggest;

	index = -1;
	biggest = stack.stack[++index];
	while (++index < stack.length)
		if (stack.stack[index] > biggest)
			biggest = stack.stack[index];
	return (biggest);
}

