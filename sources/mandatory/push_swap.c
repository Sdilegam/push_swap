/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:00:13 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/03/29 15:49:08 by sdi-lega         ###   ########.fr       */
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
		error();
	return (number);
}

void	are_parameters_ok(int argc, char *argv[])
{
	int	index;

	index = -1;
	if (argc < 2)
	{
		error();
	}
	while (*argv)
	{	
		while (**argv)
		{
			if (is_digit(**argv) == FALSE && is_space(**argv) == FALSE)
			{
				error();
			}
			(*argv)++;
		}
		argv++;
	}
}

int	main(int argc, char *argv[])
{
	struct s_stack	stacks[2];
	int				index;

	index = 0;
	are_parameters_ok(argc, argv);
	stacks[0].length = argc - 1;
	stacks[0].stack = malloc (stacks[0].length);
	while (++index != argc)
	{
		stacks[0].stack[index - 1] = parameters_handler(argv[index]);
	}
	index = 0;
	while (++index != argc)
	{
		printf ("%d\n", stacks[0].stack[index - 1]);
	}
	free (stacks[0].stack);
	return (0);
}
