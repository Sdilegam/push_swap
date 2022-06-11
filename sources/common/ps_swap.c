/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:11:44 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/11 01:58:40 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comn_index.h"

int	swap(t_stack *stacks, int id)
{
	int	temp;

	if (stacks[id].length < 2)
		return (0);
	temp = stacks[id].stack[0];
	stacks[id].stack[0] = stacks[id].stack[1];
	stacks[id].stack[1] = temp;
	return (1);
}

int	swap_both(t_stack *stacks, int id)
{
	(void) id;
	swap(stacks, A);
	swap(stacks, B);
	return (1);
}
