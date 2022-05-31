/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:07:37 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/29 19:38:35 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_index.h"

t_l_list	*function_name(char *string)
{
	t_l_list	*instructions;
	
	instructions = malloc(sizeof (t_l_list));
	instructions->id = 0;
	if (!ft_strcmp("ra\n", string) || !ft_strcmp("rb\n", string))
		instructions->move = &rotate;
	else if (!ft_strcmp("rra\n", string) || !ft_strcmp("rrb\n", string))
		instructions->move = &rev_rotate;
	else if (!ft_strcmp("pa\n", string) || !ft_strcmp("pb\n", string))
		instructions->move = &push;
	else if (!ft_strcmp("sa\n", string) || !ft_strcmp("sb\n", string))
		instructions->move = &swap;
	else if (!ft_strcmp("rrr\n", string))
		instructions->move = &rev_rotate_both;
	else if (!ft_strcmp("rr\n", string))
		instructions->move = &rotate_both;
	else if (!ft_strcmp("ss\n", string))
		instructions->move = &swap_both;
	if (!ft_strcmp("rb\n", string) || !ft_strcmp("rrb\n", string) || !ft_strcmp("pb\n", string) || !ft_strcmp("sb\n", string))
		instructions->id = 1;
	return (instructions);
}


t_l_list	*read_input(void)
{
	t_l_list	*instructions;
	t_l_list	**cursor;
	char	*buf;

	buf = get_next_line(0);
	instructions = function_name(buf);
	cursor = &instructions;
	if (!cursor)
		return (0);
	while (buf)
	{
		free(buf);
		buf = get_next_line(0);
		(*cursor)->next = function_name(buf);
		cursor = &((*cursor)->next);
	}
	free(buf);
	*cursor = 0;
	return (instructions);
}


int	main(int argc, char *argv[])
{
	t_stack		*stacks;
	t_l_list	*moves;

	
	are_parameters_ok(3, argv);
	stacks = stacks_init(argc - 1, argv);
	// print_stack(stacks);
	moves = read_input();
	while (moves)
	{
			moves->move(stacks, moves->id);
			// print_stack(stacks);
			moves = moves->next;
	}
	if (is_sorted(stacks[0]))
		return(ft_printf("OK\n"));
	return(ft_printf("KO\n"));
}
