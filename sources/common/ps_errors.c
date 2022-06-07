/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:18:14 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/07 12:51:55 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comn_index.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free(void **ptr)
{
	free(*ptr);
	*ptr = 0;
}

void	free_stack(t_stack **stack)
{
	ft_free((void **)&stack[0][0].stack);
}

void	free_stacks(t_stack **stacks)
{
	ft_free((void **)&stacks[0][0].stack);
	ft_free((void **)&stacks[0][1].stack);
	ft_free((void **)stacks);
}
