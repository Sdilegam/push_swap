/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacks_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:26:16 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/10 13:29:22 by sdi-lega         ###   ########.fr       */
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
	stacks[0].stack = 0;
	stacks[1].stack = 0;
	stacks[0].length = length;
	if (!mem_alloc((void **)&stacks[0].stack, stacks[0].length * sizeof(int)))
		safe_exit(&stacks);
	while (++index != length + 1)
	{
		stacks[0].stack[index - 1] = parameters_handler(parameters[index]);
		if (in_stack(stacks[0].stack, index - 1) == TRUE)
			safe_exit(&stacks);
	}
	stacks[1].length = 0;
	if (!mem_alloc((void **)&stacks[1].stack, stacks[1].length * sizeof(int)))
		safe_exit(&stacks);
	return (stacks);
}
