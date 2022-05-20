/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:00:13 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/20 14:13:17 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

// int	main(int argc, char *argv[])
// {
// 	t_stack	*stacks;
// 	// t_stack	sorted_stack;
// 	int		index;

// 	index = 0;
// 	are_parameters_ok(argc, argv);
// 	stacks = stacks_init(argc - 1, argv);
// 	print_and_sort (stacks);
// 	// print_stack(stacks);
// 	return (0);
// }
int	main(int argc, char *argv[])
{
	t_stack	*stacks;
	int		index;
	// int		index2;

	// index2 = -1;
	are_parameters_ok(argc, argv);
	stacks = stacks_init(argc - 1, argv);
	index = find_best(stacks);
	move(index, stacks, get_functions(1));
	sort(stacks, get_functions(1));
	// print_stack(stacks);
	free(stacks[0].stack);
	free(stacks[1].stack);
	free(stacks);
	return (0);
}
