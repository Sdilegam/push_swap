/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:58:50 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/19 07:51:22 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

int	print_rotate(t_stack *stacks, int id)
{
	ft_printf("r%c\n", 'a' + id);
	return (rotate(stacks, id));
}

int	print_rotate_both(t_stack *stacks)
{
	ft_printf("rr\n");
	return (rotate_both(stacks));
}

int	print_rev_rotate(t_stack *stacks, int id)
{
	ft_printf("rr%c\n", 'a' + id);
	return (rev_rotate(stacks, id));
}

int	print_rev_rotate_both(t_stack *stacks)
{
	ft_printf("rrr\n");
	return (rev_rotate_both(stacks));
}
