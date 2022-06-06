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
	int	*list;

	list = stack.stack;
	if ((number > stack.lim.last || number < stack.lim.first) && index == get_index(stack, stack.lim.first))
		return (TRUE);
	if (index == 0)
	{
		if (list[index] < number || number < list[stack.length - 1])
			return (FALSE);
	}
	else
		if (list[index] < number || number < list[index - 1])
			return (FALSE);
	return (TRUE);
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
	while (++index != stacks[0].length / 2 + 1 && (index <= temp.a || index < temp.b))
	{
		index_b = -1;
		while (++index_b < stacks[1].length && (index_b <= temp.a || index_b < temp.b)) 
			if (check_item_out(stacks[1].stack[index_b], index, stacks[0]) == TRUE)
			{	
				bigger = index;
				if (index_b > index)
					bigger = index_b;
				if (temp.a > bigger || temp.b > bigger)
				{
					temp.a = index;
					temp.b = index_b;
				}
			}
	}
	index = 0;
	while (++index != stacks[0].length / 2 + 1 && (index <= abs(temp.a) || index < abs(temp.b)))
	{
		index_b = 0;
		while (++index_b <= stacks[1].length && (index_b <= abs(temp.a) || index_b < abs(temp.b)))
			if (check_item_out(stacks[1].stack[stacks[1].length - index_b], stacks[0].length - index, stacks[0]) == TRUE)
			{
				bigger = index;
				if (index_b > index)
					bigger = index_b ;
				if (abs(temp.a) > bigger || abs(temp.b) > bigger)
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
	t_moves moves;

	steps = 0;
	stacks[0].lim.first = get_smallest(stacks[0]);
	stacks[0].lim.last = get_biggest(stacks[0]);
	while (stacks[1].length != 0)
	{	
		steps += move_to(get_next_change(stacks), stacks, f);
		steps += f.push(stacks, 0);
	}
	moves.a = get_index(stacks[0], get_smallest(stacks[0]));
	moves.b = 0;
	if (moves.a > stacks[0].length / 2)
		moves.a = -stacks[0].length + moves.a; 
	steps += move_to(moves, stacks, f);
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
		swap(stacks, 0);
		if (check_item_in(0, stacks[0]) == 0 && !is_sorted(stacks[0]))
			swap(stacks, 0);
		else
		{
			steps ++;
			if (f.rotate == &print_rotate)
				ft_printf("sa\n");
		}
		while (check_item_in(0, stacks[0]) == 0 && \
		!is_sorted(stacks[0]))
		{
			steps += f.push(stacks, 1);
		}
		if (check_item_in(0, stacks[0]) == 1 &&
		!is_sorted(stacks[0]))
		{
				steps += f.rotate(stacks, 0);
		}
	}
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

	f = get_functions(0);
	offset = -1;

	n_stacks = copy_stacks(stacks);
	number = sort(n_stacks, f);
	answer = 0;
	while (++offset != stacks->length / 4)
	{
		copy_stack(n_stacks->stack, stacks->stack, stacks->length);
		index = -1;
		while (++index <= offset)
			rev_rotate(n_stacks, 0);
		// print_stack(n_stacks);
		temp = sort(n_stacks, f);
		// ft_printf("%d\n", temp + offset);
		if (temp + offset + 1 < number)
		{
			number = temp + offset + 1;
			// ft_printf("best : %d\n", number);
			answer = -offset - 1;
		}
	}
	offset = -1;
	while (++offset != stacks->length / 4)
	{
		copy_stack(n_stacks->stack, stacks->stack, stacks->length);
		index = -1;
		while (++index < offset)
			rotate(n_stacks, 0);
		// print_stack(n_stacks);
		temp = sort(n_stacks, f);
		// ft_printf("%d\n", temp + offset);
		if (temp + offset + 1 < number)
		{
			number = temp + offset + 1;
			// ft_printf("best : %d\n", number);
			answer = offset;
		}
	}
	// ft_printf("%d\n", answer);
	return (answer);
}
