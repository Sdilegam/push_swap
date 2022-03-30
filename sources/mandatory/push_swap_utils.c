/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:02:50 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/03/29 18:20:20 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_digit(char chara)
{
	if ('0' <= chara && chara <= '9')
		return (TRUE);
	return (FALSE);
}

t_bool	is_space(char chara)
{
	if (chara == ' ')
		return (TRUE);
	return (FALSE);
}

t_bool	is_sign(char chara)
{
	if (chara == '-' || chara == '+')
		return (TRUE);
	return (FALSE);
}
