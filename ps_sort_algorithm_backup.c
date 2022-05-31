/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:51:11 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/31 06:37:46 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

t_bool	check_item_in(int index, t_stack stack)
{
	int	i;
	int	*list;
	int	start;
	int	number;

	list = stack.stack;
	i = -1;
	number = -1;
	start = get_index(stack, stack.lim.last);
	while (start - ++i != index)
	{
		if (list[index] > list[start - i])
			number ++;
		if (start - i == 0)
		{
			start = stack.length;
			i = 0;
		}
	}
	if (number > 1)
		return (FALSE);
	i = -1;
	start = get_index(stack, stack.lim.first);
	while (start + ++i != index)
	{
		if (list[index] < list[start + i])
			return (FALSE);
		if (start + i == stack.length - 1)
		{
			start = 0;
			i = -1;
		}
	}
	return (TRUE);
}

t_bool	check_item_out(int number, int index, t_stack stack)
{
	int	i;
	int	*list;
	int	start;

	list = stack.stack;
	i = -1;
	start = get_index(stack, stack.lim.last);
	if ((number > stack.lim.last || number < stack.lim.first) && index == get_index(stack, stack.lim.first))
		return (TRUE);
	while (start - ++i != index)
	{
		if (number > list[start - i])
			return (FALSE);
		if (start - i == 0 && index != 0)
		{
			start = stack.length;
			i = 0;
		}
	}
	if (number > list[start - i])
		return (FALSE);
	i = -1;
	start = get_index(stack, stack.lim.first);
	while (start + ++i != index)
	{
		if (number < list[start + i])
			return (FALSE);
		if (start + i == stack.length - 1)
		{
			start = 0;
			i = -1;
		}
	}
	return (TRUE);
}

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
t_bool	check_place(int element, t_stack stack)
{
	if (stack.stack[0] == get_smallest(stack))
		if (element < stack.stack[0] || element > stack.stack[stack.length -1])
			return (TRUE);
	if (check_item(element, stack) == TRUE)
		return (TRUE);
	return (FALSE);
}

t_moves	get_next_change(t_stack *stacks)
{
	int	index;
	int	index_b;
	t_moves	temp;
	int	bigger;

	index = -1;
	temp.a = MAX_INT;
	temp.b = MAX_INT;
	while (++index != stacks[0].length)
	{
		index_b = -1;
		if (check_item_in(index, stacks[0]) == FALSE)
		{
			if (temp.a > bigger && temp.b > bigger)
				{
					temp.a = index;
					temp.b = 0;
				}
		}
		while (++index_b < stacks[1].length)
			if (check_item_out(stacks[1].stack[index_b], index, stacks[0]) == TRUE)
			{	
				bigger = index;
				if (index_b > index)
					bigger = index_b;
				if (temp.a > bigger && temp.b > bigger)
				{
					temp.a = index;
					temp.b = index_b;
				}
			}
	}
	index = 0;
	while (++index > stacks[0].length)
	{
		index_b = -1;
		if (check_item_in(index, stacks[0]) == FALSE)
		{
			if (abs(temp.a) > bigger && abs(temp.b) > bigger)
				{
					temp.a = -index;
					temp.b = 0;
				}
		}
		while (++index_b < stacks[1].length)
			if (check_item_out(stacks[1].stack[index_b], stacks[0].length - index, stacks[0]) == TRUE)
			{
				bigger = index;
				if (abs(index_b - stacks[B].length) + 1 > index)
					bigger = abs(index_b - stacks[B].length) + 1 ;
				if (abs(temp.a) > bigger && abs(temp.b) > bigger)
				{
					temp.a = -index;
					temp.b = -index_b;
				}
			}
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
		steps += move_to(get_next_change(stacks), stacks, f);
		if (check_item_out(stacks[1].stack[0], 0, stacks[0]))
		{
			steps += push(stacks, 1);
		}
		if (stacks[0].stack[0] > stacks[0].stack[1])
		{	
			swap(stacks, 0);
			if (check_item_in(0, stacks[0]) == 0 && !is_sorted(stacks[0]))
				swap(stacks, 0);
			else if (f.rotate == &print_rotate)
			{
				ft_printf("sa\n");
			}
		}
		if (check_item_in(0, stacks[0]) == 0 && \
		!is_sorted(stacks[0]))
		{
			steps += f.push(stacks, 1);
		}
		if (check_item_in(0, stacks[0]) == 1 && \
		!is_sorted(stacks[0]))
		{
			if (get_index(stacks[1], get_smallest(stacks[1])) > 0)
				steps += f.rotate_both(stacks, 1);
			else
				steps += f.rotate(stacks, 0);
		}
	}
	// print_stack(stacks);
	steps += empty_b(stacks, f);
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
	int			index;

	f.push = &push;
	f.rotate = &rotate;
	f.rev_rotate = &rev_rotate;
	f.rotate_both = &rotate_both;
	offset = 0;
	n_stacks = copy_stack(stacks);
	number = sort(n_stacks, f);
	// ft_printf("%d\n", number);
	answer = 0;
	while (++offset != stacks[0].length / 2)
	{
		free(n_stacks[0].stack);
		free(n_stacks[1].stack);
		free(n_stacks);
		n_stacks = copy_stack(stacks);
		index = 0;
		while (++index < offset)
			rev_rotate(n_stacks, 0);
		// print_stack(n_stacks);
		temp = sort(n_stacks, f);
		// ft_printf("%d\n", temp);
		if (temp + offset < number)
		{
			// ft_printf("%d\n", temp + offset);
			number = temp + offset;
			answer = -offset;
		}
	}
	offset = 0;
	while (++offset != stacks[0].length / 2)
	{
		free(n_stacks[0].stack);
		free(n_stacks[1].stack);
		free(n_stacks);
		n_stacks = copy_stack(stacks);
		index = 0;
		while (++index < offset)
			rotate(n_stacks, 0);
		// print_stack(n_stacks);
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
