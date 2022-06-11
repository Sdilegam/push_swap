/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacks_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:26:16 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/11 02:00:05 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comn_index.h"

t_bool	in_stack(int *stack, int len)
{
	int	index;

	index = -1;
	while (++index < len)
		if (stack[index] == stack[len])
			return (TRUE);
	return (FALSE);
}

t_stack	*stacks_init(int length, char **parameters)
{
	t_stack	*stacks;
	int		index;

	index = 0;
	if (!mem_alloc((void **)&stacks, 2 * sizeof(t_stack)))
		error();
	stacks[A].stack = 0;
	stacks[B].stack = 0;
	stacks[A].length = length;
	if (!mem_alloc((void **)&stacks[A].stack, stacks[A].length * sizeof(int)))
		safe_exit(&stacks);
	while (++index != length + 1)
	{
		stacks[A].stack[index - 1] = parameters_handler(parameters[index]);
		if (in_stack(stacks[A].stack, index - 1) == TRUE)
			safe_exit(&stacks);
	}
	stacks[B].length = 0;
	if (!mem_alloc((void **)&stacks[B].stack, stacks[B].length * sizeof(int)))
		safe_exit(&stacks);
	return (stacks);
}
