/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:51:11 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/08 15:55:43 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	in_stack(int element, t_stack stack)
{
	int	index;

	index = -1;
	while (++index < stack.length)
		if (element == stack.stack[index])
			return (index + 1);
	return (0);
}

int	sort(t_stack *stacks, t_stack landmark)
{
	int	index;
	int	index2;
	int	reverse_index;
	int	etalon;

	reverse_index = 1;
	index = -1;
	index2 = -1;
	while (++index < landmark.length)
	{
		etalon = in_stack(landmark.stack[index], stacks[0]);
		if (etalon)
		{
			while (index2 < etalon)
			{
				while (stacks->stack[0] == landmark.stack[landmark.length - reverse_index])
				{
					push(stacks, 1);
					printf("pb\n");
					rotate(stacks, 1);
					printf("rb\n");
					index2 ++;
					reverse_index ++;
				}
				if (index2 < etalon)
				{
					rotate(stacks, 0);
					printf("ra\n");
					index2 ++;
				}
			}
			index2 = -1;
		}
	}
	return (0);
}
