/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:58:59 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/26 14:59:11 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
