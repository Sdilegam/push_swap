/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manda_print_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:58:50 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/04 10:43:19 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

void	print_rotate(t_stack *stacks, int id)
{
	rotate(stacks, id);
	ft_printf("r%c\n", 'a' + id);
}

void	print_rotate_both(t_stack *stacks)
{
	rotate_both(stacks);
	ft_printf("rr\n");
}

void	print_rev_rotate(t_stack *stacks, int id)
{
	rev_rotate(stacks, id);
	ft_printf("rr%c\n", 'a' + id);
}

void	print_rev_rotate_both(t_stack *stacks)
{
	rev_rotate_both(stacks);
	ft_printf("rrr\n");
}
