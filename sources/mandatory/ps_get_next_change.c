/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_next_change.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:02:37 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/09 19:12:42 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

t_moves	compare_moves(t_moves prev, int new_a, int new_b)
{
	int	biggest;

	biggest = abs(new_a);
	if (abs(new_b) > abs(new_a))
		biggest = abs(new_b);
	if (abs(prev.a) > biggest || abs(prev.b) > biggest)
	{
		prev.a = new_a;
		prev.b = new_b;
	}
	return (prev);
}

t_moves	get_next_change(t_stack *s)
{
	int		i_a;
	int		i_b;
	t_moves	t;

	i_a = -1;
	t.a = MAX_INT;
	t.b = MAX_INT;
	while (++i_a != s[0].length / 2 + 1 && (i_a <= t.a || i_a < t.b))
	{
		i_b = -1;
		while (++i_b < s[1].length && (i_b <= t.a || i_b < t.b))
			if (check_item_out(s[1].stack[i_b], i_a, s[0]) == TRUE)
				t = compare_moves(t, i_a, i_b);
	}
	i_a = 0;
	while (++i_a != s[0].length / 2 + 1 && (i_a <= abs(t.a) || i_a < abs(t.b)))
	{
		i_b = 0;
		while (++i_b <= s[1].length && (i_b <= abs(t.a) || i_b < abs(t.b)))
			if (check_item_out(s[1].stack[s[1].length - i_b], \
			s[0].length - i_a, s[0]) == TRUE)
				t = compare_moves(t, -i_a, -i_b);
	}
	return (t);
}
