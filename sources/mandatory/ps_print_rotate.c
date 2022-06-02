/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:58:50 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/02 14:43:44 by sdi-lega         ###   ########.fr       */
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

	if (steps.a >= 0 && steps.b >= 0 )
	{
		index = -1;
		while (++index < steps.a || index < steps.b)
		{
			if (index < steps.a && index < steps.b)
				f.rotate_both(stack, 0);
			else if (index < steps.a)
				f.rotate(stack, 0);
			else if (index < steps.b)
				f.rotate(stack, 1);
		}
		return (index);
	}
	else if (steps.a <= 0 && steps.b <= 0 )
	{
		index = -1;
		while (++index < -steps.a || index < -steps.b)
		{
			if (index < -steps.a && index < -steps.b)
				f.rev_rotate_both(stack, 0);
			else if (index < -steps.a)
				f.rev_rotate(stack, 0);
			else if (index < -steps.b)
				f.rev_rotate(stack, 1);
		}
		return (index);
	}
	return (0);
}
