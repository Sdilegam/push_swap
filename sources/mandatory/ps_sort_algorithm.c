/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:51:11 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/24 23:11:55 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

int	check_item(int element, t_stack stack)
{
	int	index;
	int	last;

	last = stack.lim.last;
	index = -1;
	if (stack.stack[0] == get_smallest(stack))
		if (element < stack.stack[0] || element > stack.stack[stack.length -1])
			return (TRUE);
	if (last < element)
		return (0);
	while (stack.stack[++index] != last)
	{
		if (stack.stack[index] < element)
			return (FALSE);
	}
	index = stack.length;
	while (stack.stack[--index] != last)
	{
		if (stack.stack[index] > element)
			return (FALSE);
	}
	return (TRUE);
}

int	check_item1(int element, t_stack stack)
{
	int	index;
	int	last;
	int i;

	last = stack.lim.last;
	index = -1;
	i = 0;
	if (stack.stack[0] == get_smallest(stack))
		if (element < stack.stack[0] || element > stack.stack[stack.length -1])
			return (TRUE);
	if (last < element)
		i++;
	while (stack.stack[++index] != last)
	{
		if (stack.stack[index] < element)
			return (i++);
		if (i > 1)
			return (FALSE);
	}
	index = stack.length;
	while (stack.stack[--index] != last)
	{
		if (stack.stack[index] > element)
			return (FALSE);
	}
	return (TRUE);
}

t_bool	check_place(int element, t_stack stack)
{
	if (stack.stack[0] == get_smallest(stack))
		if (element < stack.stack[0] || element > stack.stack[stack.length -1])
			return (TRUE);
	if (check_item(element, stack) == TRUE)
		return (TRUE);
	return (FALSE);
}

int	get_next_change(t_stack *stacks)
{
	int	index;
	int	index_b;
	int	temp;

	index = 0;
	temp = 3000;
	while (index != stacks[0].length)
	{
		index_b = -1;
		while (++index_b < stacks[1].length)
			if (check_item(stacks[1].stack[index_b], stacks[0]) == TRUE)
				if (index < temp)
					temp = index;
		index += move_to(1, &stacks[0], get_functions(0));
	}
	move_to(-index, &stacks[0], get_functions(0));
	index = 0;
	while (abs(index) != stacks[0].length)
	{
		index_b = -1;
		while (++index_b < stacks[1].length)
			if (check_item(stacks[1].stack[index_b], stacks[0]) == TRUE)
				if (abs(index) < abs(temp))
					temp = index;
		index -= move_to(-1, &stacks[0], get_functions(0));
	}
	return (temp);
}
int	empty_b(t_stack *stacks, t_functions f)
{
	int	steps;

	steps = 0;
	while (stacks[1].length != 0)
	{	
		stacks[0].lim.first = get_smallest(stacks[0]);
		stacks[0].lim.last = get_biggest(stacks[0]);
		steps += move_to(get_next_change(stacks), stacks, f);
		while (check_item(stacks[1].stack[0], stacks[0]) == FALSE && \
		get_next_change(stacks) == 0)
		{
			steps += f.rotate(stacks, 1);
		}
		steps += f.push(stacks, 0);
	}
	while (stacks[0].stack[0] != get_smallest(stacks[0]))
	{
		steps += f.rotate(stacks, 0);
	}
	return (steps);
}

int	sort(t_stack *stacks, t_functions f)
{
	int	steps;

	steps = 0;
	stacks[0].lim.first = stacks[0].stack[0];
	stacks[0].lim.last = stacks[0].stack[stacks[0].length - 1];
	while (!is_sorted(stacks[0]))
	{
		if (stacks[1].length != 0)
			if (check_item(get_smallest(stacks[1]), stacks[0]) == 1)
			{
				while (get_index(stacks[1], get_smallest(stacks[1])) > 0)
					steps += f.rotate(stacks, 1);
				steps += f.push(stacks, 0);
			}
		while (check_item(stacks[0].stack[0], stacks[0]) == 0 && \
		!is_sorted(stacks[0]))
		{
			steps += f.push(stacks, 1);
		}
		if (check_item(stacks[0].stack[0], stacks[0]) == 1 && \
		!is_sorted(stacks[0]))
		{
			if (get_index(stacks[1], get_smallest(stacks[1])) > 0)
				steps += f.rotate_both(stacks);
			else
				steps += f.rotate(stacks, 0);
		}
	}
	// print_stack(stacks);
	// steps += empty_b(stacks, f);
	return (steps);
}

int	find_best(t_stack *stacks)
{
	int			offset;
	int			answer;
	int			number;
	int			temp;
	t_stack		*n_stacks;
	t_functions	f;

	f.push = &push;
	f.rotate = &rotate;
	f.rev_rotate = &rev_rotate;
	f.rotate_both = &rotate_both;
	offset = 0;
	n_stacks = copy_stack(stacks);
	number = sort(n_stacks, f);
	answer = 0;
	while (++offset != n_stacks[0].length / 2)
	{
		free(n_stacks[0].stack);
		free(n_stacks[1].stack);
		free(n_stacks);
		n_stacks = copy_stack(stacks);
		move_to(-offset, n_stacks, f);
		temp = sort(n_stacks, f);
		if (temp + offset < number)
		{
			// ft_printf("%d\n", temp + offset);
			number = temp + offset;
			answer = -offset;
		}
	}
	offset = 0;
	while (++offset != n_stacks[0].length / 2)
	{
		free(n_stacks[0].stack);
		free(n_stacks[1].stack);
		free(n_stacks);
		n_stacks = copy_stack(stacks);
		move_to(offset, n_stacks, f);
		temp = sort(n_stacks, f);
		if (temp + offset < number)
		{
			// ft_printf("%d\n", temp +offset);
			number = temp + offset;
			answer = offset;
		}
	}
	// ft_printf("%d\n", answer);
	return (answer);
}
