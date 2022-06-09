/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_linked_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:39:46 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/09 19:49:37 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_index.h"

int	create_link(t_l_list **list)
{
	*list = malloc(sizeof (t_l_list));
	if (!*list)
		return (0);
	(*list)->id = 0;
	(*list)->move = 0;
	(*list)->next = 0;
	return (1);
}

void	free_list(t_l_list *list)
{
	t_l_list	*temp;

	while (list)
	{
		temp = list->next;
		ft_free_ptr((void **)&list);
		list = temp;
	}
}
