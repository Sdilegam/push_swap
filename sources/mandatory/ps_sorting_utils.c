/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:48:37 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/24 13:49:09 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

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

