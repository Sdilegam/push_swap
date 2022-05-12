/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comn_ps_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:02:50 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/04 11:15:48 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comn_index.h"

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

t_bool	is_in_stack(int element, t_stack stack)
{
	int	index;

	index = -1;
	while (++index < stack.length)
		if (element == stack.stack[index])
			return (index + 1);
	return (0);
}
