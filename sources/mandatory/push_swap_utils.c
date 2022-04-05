/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:02:50 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/05 21:54:43 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stacks)
{
	int	index;

	index = -1;
	printf ("sorted_a: [");
	while (++index < stacks->length)
	{
		printf ("%d", stacks->stack[index]);
		if (index != stacks->length -1)
			printf (", ");
	}
	printf ("]\n");
	index = -1;
	stacks++;
	printf ("sorted_b: [");
	while (++index < stacks->length)
	{
		printf ("%d", stacks->stack[index]);
		if (index != stacks->length -1)
			printf (", ");
	}
	printf ("]\n");
}

t_bool	is_digit(char chara)
{
	if ('0' <= chara && chara <= '9')
		return (TRUE);
	return (FALSE);
}

t_bool	is_space(char chara)
{
	if (chara == ' ')
		return (TRUE);
	return (FALSE);
}

t_bool	is_sign(char chara)
{
	if (chara == '-' || chara == '+')
		return (TRUE);
	return (FALSE);
}
