/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:18:14 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/11 02:01:54 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comn_index.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_ptr(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
}

void	free_stacks(t_stack **stacks)
{
	if (*stacks)
	{
		ft_free_ptr((void **)&stacks[0][A].stack);
		ft_free_ptr((void **)&stacks[0][B].stack);
		ft_free_ptr((void **)stacks);
	}
}

void	safe_exit(t_stack **stacks)
{
	free_stacks(stacks);
	error();
}
