/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comn_ps_stacks_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:26:16 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/04 11:26:40 by sdi-lega         ###   ########.fr       */
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
		exit (1);
	stacks[0].length = length;
	stacks[0].stack = malloc(stacks[0].length * sizeof(int));
	if (!stacks[0].stack)
		exit (1);
	while (++index != length + 1)
		stacks[0].stack[index - 1] = parameters_handler(parameters[index]);
	stacks[1].length = 0;
	stacks[1].stack = calloc(stacks[1].length, sizeof(int));
	if (!stacks[1].stack)
		exit (1);
	return (stacks);
}
