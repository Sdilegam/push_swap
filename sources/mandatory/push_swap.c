/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:00:13 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/03/31 16:33:58 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\ni", 6);
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

int	main(int argc, char *argv[])
{
	struct s_stack	stacks[2];
	int				index;

	index = 0;
	are_parameters_ok(argc, argv);
	stacks[0].length = argc - 1;
	stacks[1].length = 0;
	stacks[0].stack = calloc(stacks[0].length, sizeof(int));
	stacks[1].stack = calloc(stacks[1].length, sizeof(int));
	while (++index != argc)
	{
		stacks[0].stack[index - 1] = parameters_handler(argv[index]);
	}
	index = 0;
	print_stack(stacks);
	while (stacks[0].length > 0)
	{
		push(stacks, 1);
	}
	print_stack(stacks);
	while (stacks[1].length > 0)
	{
		push(stacks, 0);
	}
	print_stack(stacks);
	print_stack(arrange_stack(stacks));
	return (0);
}
