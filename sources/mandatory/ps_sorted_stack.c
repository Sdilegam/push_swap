/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   landmark.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 08:18:19 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/04 13:07:47 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_stack(int **stack_to, int *stack_from, int length)
{
	int	index;

	index = -1;
	while (++index < length)
		(*stack_to)[index] = stack_from[index];
}

t_stack	arrange_stack(t_stack *stacks)
{
	t_stack	sort_a;
	int		index;
	int		temp;

	index = -1;
	sort_a.length = stacks->length;
	sort_a.stack = malloc (stacks->length);
	copy_stack(&(sort_a.stack), stacks->stack, stacks->length);
	sort_a.length = stacks->length;
	while (++index < stacks->length - 1)
	{
		if (sort_a.stack[index] > sort_a.stack[index + 1])
		{
			while (index >= 0 && sort_a.stack[index] > sort_a.stack[index + 1])
			{
				temp = sort_a.stack[index];
				sort_a.stack[index] = sort_a.stack[index + 1];
				sort_a.stack[index + 1] = temp;
				index --;
			}
		}
	}
	return (sort_a);
}
