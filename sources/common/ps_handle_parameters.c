/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_handle_parameters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:58:59 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/11 15:18:18 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comn_index.h"

void	are_parameters_ok(int argc, char *argv[])
{
	int	number;
	int	digit;

	digit = -1;
	number = 0;
	if (argc < 2)
		exit (0);
	while (argv[++number])
	{	
		if (!argv[number][0])
			error();
		while (argv[number][++digit])
		{	
			if (is_digit(argv[number][digit]) == FALSE)
			{
				if (digit != 0 || argv[number][digit] != '-' || \
				!argv[number][digit + 1])
					error();
			}
		}
		digit = -1;
	}
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
		if (number > MAX_INT || number < MIN_INT)
			error ();
	}
	if (negative == TRUE)
		number *= -1;
	return (number);
}
