/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:51:11 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/16 15:34:07 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

int	get_smallest(int *stack)
{
	int	index;
	int	smallest;

	index = -1;
	smallest = stack[++index];
	while (stack[++index])
		if (stack[index] < smallest)
			smallest = stack[index];
	return (smallest);
}

int	check_item(int start, t_stack stack)
{
	int	index;
	int	last;

	last = stack.lim.last;
	index = -1;
	if (stack.stack[0] == stack.lim.first && start > last)
		return(1);
	while (stack.stack[++index] != last)
	{
		// ft_printf("%d < %d, len: %d \n", stack[index], start, last);
		if (stack.stack[index] < start)
			return (0);
	}
	if (stack.stack[index] < start)
		return (0);
	return (1);
}

int	get_next_change(t_stack *stacks)
{
	int	index;
	int	minus;

	index = 0;
	minus = 0;
	while (stacks[0].stack[index] != stacks[0].lim.last && stacks[0].stack[index])
	{
		if (check_item(get_smallest(stacks[1].stack), stacks[0]) == 0)
			return (index - minus);
		if (check_item(stacks[0].stack[0], stacks[0]) == 0)
			minus++;
		index++;
	}
	return (-1);
}

t_bool	get_index(int *stack, int item)
{
	int	index;

	index = -1;
	while (stack[++index])
		if (stack[index] == item)
			return (index);
	return (-1);
}


int	sort(t_stack *o_stacks)
{
	int		index;
	int		len;
	int		steps;
	t_stack	*stacks;

	stacks = malloc (2 * sizeof(t_stack));
	stacks[0].stack = malloc(o_stacks[0].length * sizeof(int));
	stacks[1].stack = malloc(0 * sizeof(int));
	copy_stack(&stacks[0].stack, o_stacks[0].stack, o_stacks[0].length);
	stacks[0].length = o_stacks[0].length;
	stacks[1].length = 0;
	steps = 0;
	len = stacks[0].length;
	stacks[0].lim.first = stacks[0].stack[0];
	stacks[0].lim.last = stacks[0].stack[stacks[0].length - 1];
	index = -1;
	// printf("first element: %d\n", stacks[0].stack[0]);
	while (stacks[0].stack[0] != stacks[0].lim.last)
	{
		if (stacks[1].length != 0)
			if (check_item(get_smallest(stacks[1].stack), stacks[0]) == 1)
			{
				while (get_index(stacks[1].stack, get_smallest(stacks[1].stack)) > 0)
					steps += rotate(stacks, 1);
				steps += push(stacks, 0);
			}
		if (check_item(stacks[0].stack[0], stacks[0]) == 0 && stacks[0].stack[0] != stacks[0].lim.last)
		{
			steps += push(stacks, 1);
		}
		else if (stacks[0].stack[0] != stacks[0].lim.last)
		{
			if (get_index(stacks[1].stack, get_smallest(stacks[1].stack)))
				steps += rotate_both(stacks);
			else
				steps += rotate(stacks, 0);
		}
	}
	steps += rotate(stacks, 0);
	while (stacks[1].length != 0)
	{
		if (stacks[1].length != 0)
			if (check_item(get_smallest(stacks[1].stack), stacks[0]) == 1)
			{
				while (get_index(stacks[1].stack, get_smallest(stacks[1].stack)) > 0)
					steps += rotate(stacks, 1);
				steps += push(stacks, 0);
			}
		if (get_index(stacks[1].stack, get_smallest(stacks[1].stack)))
			steps += rotate_both(stacks);
		else
			steps += rotate(stacks, 0);
	}
	while (stacks[0].stack[0] != get_smallest(stacks[0].stack))
	{
		steps += rotate(stacks, 0);
	}
	// print_stack(stacks);
	free(stacks[0].stack);
	free(stacks[1].stack);
	free(stacks);
	// print_stack(stacks);
	return (steps);
}

int	print_and_sort(t_stack *stacks)
{
	int		index;
	int		len;
	int		steps;

	steps = 0;
	len = stacks[0].length;
	stacks[0].lim.first = stacks[0].stack[0];
	stacks[0].lim.last = stacks[0].stack[stacks[0].length - 1];
	index = -1;
	// printf("first element: %d\n", stacks[0].stack[0]);
	while (stacks[0].stack[0] != stacks[0].lim.last)
	{
		if (stacks[1].length != 0)
			if (check_item(get_smallest(stacks[1].stack), stacks[0]) == 1)
			{
				while (get_index(stacks[1].stack, get_smallest(stacks[1].stack)) > 0)
					print_rotate(stacks, 1);
				print_push(stacks, 0);
			}
		if (check_item(stacks[0].stack[0], stacks[0]) == 0 && stacks[0].stack[0] != stacks[0].lim.last)
		{
			print_push(stacks, 1);
		}
		else if (stacks[0].stack[0] != stacks[0].lim.last)
		{
			if (get_index(stacks[1].stack, get_smallest(stacks[1].stack)))
				print_rotate_both(stacks);
			else
				print_rotate(stacks, 0);
		}
	}
	print_rotate(stacks, 0);
	while (stacks[1].length != 0)
	{
		if (stacks[1].length != 0)
			if (check_item(get_smallest(stacks[1].stack), stacks[0]) == 1)
			{
				while (get_index(stacks[1].stack, get_smallest(stacks[1].stack)) > 0)
					print_rotate(stacks, 1);
				print_push(stacks, 0);
			}
		if (get_index(stacks[1].stack, get_smallest(stacks[1].stack)))
			print_rotate_both(stacks);
		else
			print_rotate(stacks, 0);
	}
	while (stacks[0].stack[0] != get_smallest(stacks[0].stack))
	{
		print_rotate(stacks, 0);
	}
	// print_stack(stacks);
	return (steps);
}

int find_best(t_stack *stacks)
{
	int	offset;
	int answer;
	int	number;
	int	temp;

	offset = 0;
	number = sort(stacks);
	answer = 0;
	while (++offset != stacks[0].length / 2)
	{
		rev_rotate (stacks, 0);
		temp = sort(stacks);
		if (temp + offset < number)
		{
			number = temp + offset;
			answer = -offset;
		}
	}
	while (--offset >= 0)
		rotate (stacks, 0);
	while (++offset != stacks[0].length / 2)
	{
		rotate (stacks, 0);
		temp = sort(stacks);
		if (temp + offset < number)
		{
			number = temp + offset;
			answer = offset;
		}
	}
	while (--offset >= 0)
		rev_rotate (stacks, 0);
	return (answer);
}
// int	sort(t_stack *stacks, t_stack landmark)
// {
// 	int	index;
// 	int	index2;
// 	int	reverse_index;
// 	int	etalon;

// 	reverse_index = 1;
// 	index = -1;
// 	index2 = -1;
// 	while (++index < landmark.length)
// 	{
// 		etalon = in_stack(landmark.stack[index], stacks[0]);
// 		if (etalon)
// 		{
// 			while (index2 < etalon)
// 			{
// 				while (stacks->stack[0] == landmark.stack[landmark.length - reverse_index])
// 				{                                           
// 					push(stacks, 1);
// 					printf("pb\n");
// 					rotate(stacks, 1);§
// 					printf("rb\n");
// 					index2 ++;
// 					reverse_index ++;
// 				}
// 				if (index2 < etalon)
// 				{
// 					rotate(stacks, 0);
// 					printf("ra\n");
// 					index2 ++;
// 				}
// 			}
// 			index2 = -1;
// 		}
// 	}
// 	return (0);
// }
