/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:04:43 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/11 02:00:44 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comn_index.h"

int	rotate(t_stack *stacks, int id)
{
	int	temp;
	int	index;

	temp = stacks[id].stack[0];
	index = -1;
	while (++index < stacks[id].length - 1)
		stacks[id].stack[index] = stacks[id].stack[index + 1];
	stacks[id].stack[index] = temp;
	return (1);
}

int	rotate_both(t_stack *stacks, int id)
{
	(void) id;
	rotate(stacks, A);
	rotate(stacks, B);
	return (1);
}

int	rev_rotate(t_stack *stacks, int id)
{
	int	temp;
	int	index;

	temp = stacks[id].stack[stacks[id].length - 1];
	index = stacks[id].length;
	while (--index > 0)
		stacks[id].stack[index] = stacks[id].stack[index - 1];
	stacks[id].stack[0] = temp;
	return (1);
}

int	rev_rotate_both(t_stack *stacks, int id)
{
	(void) id;
	rev_rotate(stacks, A);
	rev_rotate(stacks, B);
	return (1);
}
