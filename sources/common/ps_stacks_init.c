/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacks_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:26:16 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/08 06:20:55 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comn_index.h"

t_stack	*stacks_init(int length, char **parameters)
{
	t_stack	*stacks;
	int		index;

	index = 0;
	stacks = malloc(2 * sizeof(t_stack));
	if (!stacks)
		safe_exit(&stacks);
	stacks[0].length = length;
	stacks[0].stack = malloc((stacks[0].length) * sizeof(int));
	if (!stacks[0].stack)
		safe_exit(&stacks);
	while (++index != length + 1)
		stacks[0].stack[index - 1] = parameters_handler(parameters[index]);
	stacks[1].length = 0;
	stacks[1].stack = malloc((stacks[1].length) * sizeof(int));
	if (!stacks[1].stack)
		safe_exit(&stacks);
	return (stacks);
}
