/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:08:45 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/07 13:25:22 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comn_index.h"

void	set_limits(t_stack *stacks, int id)
{
	if (stacks[0].stack[0] == stacks[0].lim.first && id == 1)
		stacks[0].lim.first = stacks[0].stack[1];
	if (stacks[0].stack[0] == stacks[0].lim.last && id == 1)
		stacks[0].lim.last = stacks[0].stack[stacks[0].length - 1];
	if (stacks[0].stack[0] == stacks[0].lim.first && id == 0)
	{
		if (stacks[0].stack[0] < stacks[1].stack[0])
			stacks[0].lim.last = stacks[1].stack[0];
		else
			stacks[0].lim.first = stacks[1].stack[0];
	}
}

int	push(t_stack *stacks, int id)
{
	int	index;
	int	*new1;
	int	*new2;

	set_limits(stacks, id);
	index = (stacks[id].length) + 1;
	stacks[id].length = index;
	if (stacks[1 - id].length == 0)
		return (1);
	new1 = calloc(index + 1, sizeof(int));
	new1[0] = stacks[1 - id].stack[0];
	while (--index > 0)
		new1[index] = stacks[id].stack[index - 1];
	ft_free((void **)&stacks[id].stack);
	stacks[id].stack = new1;
	stacks[1 - id].length -= 1;
	new2 = calloc(stacks[1 - id].length + 1, sizeof(int));
	index = -1;
	while (++index < stacks[1 - id].length)
		new2[index] = stacks[1 - id].stack[index + 1];
	ft_free((void **)&stacks[1 - id].stack);
	stacks[1 - id].stack = new2;
	return (1);
}
