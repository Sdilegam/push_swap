/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:11:44 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/16 14:19:23 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comn_index.h"

int	swap(t_stack *stacks, int id)
{
	int	temp;

	temp = stacks[id].stack[0];
	stacks[id].stack[0] = stacks[id].stack[1];
	stacks[id].stack[1] = temp;
	return (1);
}

int	swap_both(t_stack *stacks)
{
	swap(stacks, 0);
	swap(stacks, 1);
	return (1);
}
