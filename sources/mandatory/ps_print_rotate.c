/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:58:50 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/06 17:23:35 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

int	print_rotate(t_stack *stacks, int id)
{
	ft_printf("r%c\n", 'a' + id);
	return (rotate(stacks, id));
}

int	print_rotate_both(t_stack *stacks, int id)
{
	ft_printf("rr\n");
	return (rotate_both(stacks, id));
}

int	print_rev_rotate(t_stack *stacks, int id)
{
	ft_printf("rr%c\n", 'a' + id);
	return (rev_rotate(stacks, id));
}

int	print_rev_rotate_both(t_stack *stacks, int id)
{
	ft_printf("rrr\n");
	return (rev_rotate_both(stacks, id));
}

int	move_to(t_moves steps, t_stack *stack, t_functions f)
{
	int	index;
	int	(*rotate)(t_stack *, int);
	int	(*rotate_both)(t_stack *, int);

	index = -1;
	if (steps.a >= 0 && steps.b >= 0)
	{
		rotate_both = f.rotate_both;
		rotate = f.rotate;
	}
	else
	{
		rotate_both = f.rev_rotate_both;
		rotate = f.rev_rotate;
	}
	while (++index < abs(steps.a) || index < abs(steps.b))
	{
		if (index < abs(steps.a) && index < abs(steps.b))
			rotate_both(stack, 0);
		else if (index < abs(steps.a))
			rotate(stack, 0);
		else if (index < abs(steps.b))
			rotate(stack, 1);
	}
	return (index);
}
