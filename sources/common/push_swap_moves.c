/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:11:44 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/26 14:08:22 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stacks, int id)
{
	int	temp;
	int	index;

	temp = stacks[id].stack[0];
	index = -1;
	printf("r%c\n", 'a' + id);
	while (++index < stacks[id].length - 1)
		stacks[id].stack[index] = stacks[id].stack[index + 1];
	stacks[id].stack[index] = temp;
	return ;
}

void	rev_rotate(t_stack *stacks, int id)
{
	int	temp;
	int	index;

	temp = stacks[id].stack[stacks[id].length - 1];
	index = stacks[id].length;
	printf("rr%c\n", 'a' + id);
	while (--index > 0)
		stacks[id].stack[index] = stacks[id].stack[index - 1];
	stacks[id].stack[0] = temp;
	return ;
}

void	swap(t_stack *stacks, int id)
{
	int	temp;

	temp = stacks[id].stack[0];
	stacks[id].stack[0] = stacks[id].stack[1];
	stacks[id].stack[1] = temp;
	printf("s%c\n", 'a' + id);
	return ;
}

void	push(t_stack *stacks, int id)
{
	int	index;
	int	*new1;
	int	*new2;

	index = (stacks[id].length) + 1;
	stacks[id].length = index;
	if (stacks[1 - id].length == 0)
		return ;
	new1 = calloc(index +1, sizeof(int));
	new1[0] = stacks[1 - id].stack[0];
	while (--index > 0)
		new1[index] = stacks[id].stack[index - 1];
	free(stacks[id].stack);
	stacks[id].stack = new1;
	stacks[1 - id].length -= 1;
	new2 = calloc(stacks[1 - id].length + 1, sizeof(int));
	index = -1;
	while (++index < stacks[1 - id].length + 1)
		new2[index] = stacks[1 - id].stack[index + 1];
	free(stacks[1 - id].stack);
	stacks[1 - id].stack = new2;
	return ;
}
