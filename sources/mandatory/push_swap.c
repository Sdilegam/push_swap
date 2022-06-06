/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:00:13 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/06 17:40:42 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

int	main(int argc, char *argv[])
{
	t_stack	*stacks;
	// int		index;
	t_moves moves;
	
	// index = 0;
	moves.a = 0;
	moves.b = 0;
	are_parameters_ok(argc, argv);
	stacks = stacks_init(argc - 1, argv);
	moves.a = find_best(stacks);
	move_to(moves, stacks, get_functions(1));
	sort(stacks, get_functions(1));
	// ft_printf("%d\n", moves.a);
	// print_stack(stacks);
	free(stacks[0].stack);
	free(stacks[1].stack);
	free(stacks);
	return (0);
}
