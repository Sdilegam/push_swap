/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:00:13 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/16 15:30:35 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

int	main(int argc, char *argv[])
{
	t_stack	*stacks;
	// t_stack	sorted_stack;
	int		index;

	index = 0;
	are_parameters_ok(argc, argv);
	stacks = stacks_init(argc - 1, argv);
	index = find_best(stacks);
	if (index > 0)
		while (--index >= 0)
			print_rotate(stacks, 0);
	else if (index < 0)
		while (++index <= 0)
			print_rev_rotate(stacks, 0);
	print_and_sort(stacks);
	return (0);
}
