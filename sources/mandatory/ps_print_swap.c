/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:11:44 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/06 22:52:28 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

int	print_swap(t_stack *stacks, int id)
{
	ft_printf("s%c\n", 'a' + id);
	return (swap(stacks, id));
}

int	print_swap_both(t_stack *stacks, int id)
{
	ft_printf("ss\n");
	return (swap_both(stacks, id));
}
