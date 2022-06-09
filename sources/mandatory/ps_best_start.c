/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_best_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:17:09 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/09 19:48:55 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

void	one_way(t_stack *stacks, t_stack *t_stacks, int answer[0][2])
{
	int		offset;
	int		index;
	int		temp;

	offset = 0;
	while (++offset != stacks->length / 2)
	{
		copy_stack(t_stacks->stack, stacks->stack, stacks->length);
		index = -1;
		while (++index <= offset)
			rev_rotate(t_stacks, 0);
		temp = sort(t_stacks, get_functions(0));
		if (temp + offset + 1 < answer[0][1])
		{
			answer[0][1] = temp + offset + 1;
			answer[0][0] = -offset - 1;
		}
	}
}

void	or_another(t_stack *stacks, t_stack *t_stacks, int answer[0][2])
{
	int		offset;
	int		index;
	int		temp;

	offset = -1;
	while (++offset != stacks->length / 2)
	{
		copy_stack(t_stacks->stack, stacks->stack, stacks->length);
		index = -1;
		while (++index < offset)
			rotate(t_stacks, 0);
		temp = sort(t_stacks, get_functions(0));
		if (temp + offset + 1 < answer[0][1])
		{
			answer[0][1] = temp + offset + 1;
			answer[0][0] = offset;
		}
	}
}

int	find_best(t_stack *stacks)
{
	int		answer[1][2];
	t_stack	*t_stacks;

	t_stacks = copy_stacks(stacks);
	answer[0][1] = sort(t_stacks, get_functions(0));
	answer[0][0] = 0;
	one_way(stacks, t_stacks, answer);
	or_another(stacks, t_stacks, answer);
	free_stacks(&t_stacks);
	return (answer[0][0]);
}
