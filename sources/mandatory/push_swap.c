/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:00:13 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/08 14:41:23 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	parameters_handler(char *string)
{
	long	number;
	int		index;
	t_bool	negative;

	if (!string)
		return (0);
	negative = FALSE;
	number = 0;
	index = -1;
	if (is_sign(string[++index]) == TRUE)
	{
		index ++;
		negative = TRUE;
	}
	index --;
	while (string[++index])
	{
		number *= 10;
		number += string[index] - '0';
	}
	if (negative == TRUE)
		number *= -1;
	if (number > MAX_INT || number < MIN_INT)
		error ();
	return (number);
}

void	are_parameters_ok(int argc, char *argv[])
{
	int	number;
	int	digit;

	digit = -1;
	number = 0;
	if (argc < 2)
		error();
	while (argv[++number])
	{	
		while (argv[number][++digit])
		{
			if (is_digit(argv[number][digit]) == FALSE)
			{
				error();
			}
		}
		digit = -1;
	}
}

t_stack	*stacks_init(int length, char **parameters)
{
	t_stack	*stacks;
	int		index;

	index = 0;
	stacks = malloc(2 * sizeof(t_stack));
	if (!stacks)
		exit (1);
	stacks[0].length = length;
	stacks[0].stack = malloc(stacks[0].length * sizeof(int));
	if (!stacks[0].stack)
		exit (1);
	while (++index != length + 1)
		stacks[0].stack[index - 1] = parameters_handler(parameters[index]);
	stacks[1].length = 0;
	stacks[1].stack = calloc(stacks[1].length, sizeof(int));
	if (!stacks[1].stack)
		exit (1);
	return (stacks);
}

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
