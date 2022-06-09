/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_parse_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:37:47 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/09 18:15:31 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_index.h"

t_l_list	*read_input(t_stack *stacks)
{
	t_l_list	*instructions;
	t_l_list	**cursor;
	char		*buf;

	buf = get_next_line(0);
	instructions = 0;
	instructions = chose_move(buf, instructions, stacks);
	if (instructions)
		cursor = &instructions->next;
	while (ft_find_chara((buf), '\n') > 0 && cursor)
	{
		ft_free_ptr((void **)&buf);
		buf = get_next_line(0);
		*cursor = chose_move(buf, instructions, stacks);
		cursor = &((*cursor)->next);
	}
	ft_free_ptr((void **)&buf);
	return (instructions);
}

void	set_id(char *string, t_l_list *node)
{
	if (ft_strcmp("rb\n", string) || ft_strcmp("rrb\n", string) \
		|| ft_strcmp("pb\n", string) || ft_strcmp("sb\n", string))
		node->id = 1;
}

void	set_move(char *string, t_l_list *node)
{
	if (ft_strcmp("ra\n", string) || ft_strcmp("rb\n", string))
		node->move = &rotate;
	else if (ft_strcmp("rra\n", string) || ft_strcmp("rrb\n", string))
		node->move = &rev_rotate;
	else if (ft_strcmp("pa\n", string) || ft_strcmp("pb\n", string))
		node->move = &push;
	else if (ft_strcmp("sa\n", string) || ft_strcmp("sb\n", string))
		node->move = &swap;
	else if (ft_strcmp("rrr\n", string))
		node->move = &rev_rotate_both;
	else if (ft_strcmp("rr\n", string))
		node->move = &rotate_both;
	else if (ft_strcmp("ss\n", string))
		node->move = &swap_both;
}

t_l_list	*chose_move(char *string, t_l_list *list, t_stack *stacks)
{
	t_l_list	*instructions;

	if (!string)
		return (0);
	if (!create_link(&instructions))
		return (0);
	set_id(string, instructions);
	set_move(string, instructions);
	if (string[0] == '\n')
	{
		ft_free_ptr((void **)&instructions);
		return (0);
	}
	if (!instructions->move)
	{
		ft_free_ptr((void **)&string);
		free_list(instructions);
		free_list(list);
		free_stacks(&stacks);
		error();
	}
	return (instructions);
}
