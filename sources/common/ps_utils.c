/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:02:50 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/09 18:47:35 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comn_index.h"

// void	print_stack(t_stack *stacks)
// {
// 	int	index;

// 	index = -1;
// 	ft_printf ("sorted_a: [");
// 	while (++index < stacks->length)
// 	{
// 		ft_printf ("%d", stacks->stack[index]);
// 		if (index != stacks->length -1)
// 			ft_printf (", ");
// 	}
// 	ft_printf ("]\n");
// 	index = -1;
// 	ft_printf ("sorted_b: [");
// 	while (++index < stacks[1].length)
// 	{
// 		ft_printf ("%d", stacks[1].stack[index]);
// 		if (index != stacks[1].length -1)
// 			ft_printf (", ");
// 	}
// 	ft_printf ("]\n");
// }

int	mem_alloc(void **pointer, int size)
{
	*pointer = malloc(size);
	if (!(*pointer))
		return (0);
	return (1);
}

t_bool	is_digit(char chara)
{
	if ('0' <= chara && chara <= '9')
		return (TRUE);
	return (FALSE);
}

t_bool	is_sign(char chara)
{
	if (chara == '-' || chara == '+')
		return (TRUE);
	return (FALSE);
}
