/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:00:13 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/07 12:51:04 by sdi-lega         ###   ########.fr       */
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
	moves.a = find_best(stacks);
	move_to(moves, stacks, get_functions(1));
	sort(stacks, get_functions(1));
	free_stacks(&stacks);
	return (0);
}

// int	main(void)
// {
// 	char *test;

// 	ft_printf("test\n");
// 	test = malloc(3);
// 	ft_printf("test\n");
// 	ft_printf("test\n");
// 	ft_free((void **)&test);
// 	ft_printf("test\n");
// 	ft_printf("test\n");
// }
