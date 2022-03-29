/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:00:13 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/03/29 10:40:38 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parameters_handler(char *string)
{
	int	number;
	int				index;

	if (!string)
		return (0);
	number = 0;
	index = -1;
	while (string[++index])
	{
		number *= 10;
		number += string[index] - '0';
	}
	return (number);
}

int	main(int argc, char *argv[])
{
	struct s_stack	stack_a;
	struct s_stack	stack_b;
	int				index;

	index = 0;
	stack_a.length = argc - 1;
	stack_a.stack = malloc (stack_a.length);
	if (argc != 2)
		return (1);
	while (++index != argc)
	{
		stack_a.stack[index - 1] = parameters_handler(argv[argc]);
	}
	index = 0;
	while (++index != argc)
	{
		printf ("%d\n", stack_a.stack[index - 1]);
	}
	free (stack_a.length);
	return (0);
}
