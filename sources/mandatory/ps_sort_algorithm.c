/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:51:11 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/12 11:50:13 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

int	check_item(int start, int *stack, int len)
{
	int	index;

	index = -1;
	while (++index <= len)
	{
		// ft_printf("%d < %d, len: %d \n", stack[index], start, len);
		if (stack[index] < start)
			return (0);
	}
	return (1);
}

int	sort(t_stack *stacks)
{
	int	index;
	int	len;

	len = stacks[0].length;
	index = -1;
	while (++index <= len - 1)
	{
		if (stacks[1].length != 0)
			if (check_item(stacks[1].stack[0], stacks[0].stack, len - index - 2) == 1)
			{
				print_push(stacks, 0);
				print_rotate(stacks, 0);
			}
		if (check_item(stacks[0].stack[0], stacks[0].stack, len - index - 2) == 0)
		{
			print_push(stacks, 1);
		}
		else if (index <= len - 1)
		{
			print_rotate(stacks, 0);
		}
	}
	print_stack(stacks);
	return (0);
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
// 					rotate(stacks, 1);
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
