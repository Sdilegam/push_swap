/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorted_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 08:18:19 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/19 07:14:10 by sdi-lega         ###   ########.fr       */
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



// t_stack	arrange_stack(t_stack *stacks)
// {
// 	t_stack	sort_a;
// 	int		index;
// 	int		temp;

// 	index = -1;
// 	sort_a.length = stacks->length;
// 	sort_a.stack = malloc (stacks->length);
// 	copy_stack(&(sort_a.stack), stacks->stack, stacks->length);
// 	sort_a.length = stacks->length;
// 	while (++index < stacks->length - 1)
// 	{
// 		if (sort_a.stack[index] > sort_a.stack[index + 1])
// 		{
// 			while (index >= 0 && sort_a.stack[index] > sort_a.stack[index + 1])
// 			{
// 				temp = sort_a.stack[index];
// 				sort_a.stack[index] = sort_a.stack[index + 1];
// 				sort_a.stack[index + 1] = temp;
// 				index --;
// 			}
// 		}
// 	}
// 	return (sort_a);
// }
