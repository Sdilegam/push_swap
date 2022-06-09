/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_linked_list.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:49:49 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/09 17:50:42 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_BONUS_LINKED_LIST_H
# define PS_BONUS_LINKED_LIST_H
# include "bonus_index.h"

int		create_link(t_l_list **list);
void	free_list(t_l_list *list);

#endif /* PS_BONUS_LINKED_LIST_H */
