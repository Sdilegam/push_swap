/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manda_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:00:13 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/04 11:27:16 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

int	main(int argc, char *argv[])
{
	t_stack	*stacks;
	t_stack	sorted_stack;
	int		index;

	index = 0;
	are_parameters_ok(argc, argv);
	stacks = stacks_init(argc - 1, argv);
	sorted_stack = arrange_stack(stacks);
	print_stack(stacks);
	sort(stacks, sorted_stack);
	print_stack(stacks);
	return (0);
}
