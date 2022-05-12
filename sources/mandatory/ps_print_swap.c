/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:11:44 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/12 07:42:29 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

void	print_swap(t_stack *stacks, int id)
{
	ft_printf("s%c\n", 'a' + id);
	swap(stacks, id);
}

void	print_swap_both(t_stack *stacks)
{
	ft_printf("ss\n");
	swap_both(stacks);
}

