/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_manda_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 08:18:19 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/11 02:04:57 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

void	copy_stack(int *stack_to, int *stack_from, int length)
{
	int	index;

	index = -1;
	while (++index < length)
		stack_to[index] = stack_from[index];
}

t_stack	*copy_stacks(t_stack *stack_from)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack) * 2);
	if (new_stack)
	{
		new_stack[A].stack = malloc(sizeof(int) * stack_from[A].length);
		new_stack[B].stack = malloc(sizeof(int) * stack_from[B].length);
	}
	if (!new_stack || !new_stack[A].stack || !new_stack[B].stack)
	{
		free_stacks(&new_stack);
		safe_exit(&stack_from);
	}
	new_stack[A].length = stack_from[A].length;
	new_stack[B].length = stack_from[B].length;
	copy_stack(new_stack[A].stack, stack_from[A].stack, stack_from[A].length);
	copy_stack(new_stack[B].stack, stack_from[B].stack, stack_from[B].length);
	return (new_stack);
}

int	abs(int i)
{
	if (i >= 0)
		return (i);
	else
		return (-i);
}

t_functions	get_functions(int id)
{
	t_functions	f;

	if (id == 0)
	{
		f.rotate = &rotate;
		f.rotate_both = &rotate_both;
		f.rev_rotate = &rev_rotate;
		f.rev_rotate_both = &rev_rotate_both;
		f.swap = &swap;
		f.swap_both = &swap_both;
		f.push = &push;
	}
	else
	{
		f.rotate = &print_rotate;
		f.rotate_both = &print_rotate_both;
		f.rev_rotate = &print_rev_rotate;
		f.rev_rotate_both = &print_rev_rotate_both;
		f.swap = &print_swap;
		f.swap_both = &print_swap_both;
		f.push = &print_push;
	}
	return (f);
}
