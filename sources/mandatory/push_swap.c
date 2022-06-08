/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:00:13 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/08 07:14:59 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

int	main(int argc, char *argv[])
{
	t_stack	*stacks;
	t_moves	moves;

	moves.a = 0;
	moves.b = 0;
	are_parameters_ok(argc, argv);
	stacks = stacks_init(argc - 1, argv);
	if (argc <= 500)
		moves.a = find_best(stacks);
	move_to(moves, stacks, get_functions(1));
	sort(stacks, get_functions(1));
	free_stacks(&stacks);
	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	t_stack	*stacks;
// 	int i =-1;
	
// 	are_parameters_ok(argc, argv);
// 	stacks = stacks_init(argc - 1, argv);
// 	while (++i < 10001)
// 	{
// 		print_rotate(stacks, 0);
// 	}
// 	print_stack(stacks);
// 	free_stacks(&stacks);
// 	return (0);
// }

