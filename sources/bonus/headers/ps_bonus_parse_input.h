/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_parse_input.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:49:45 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/09 18:15:57 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_BONUS_PARSE_INPUT_H
# define PS_BONUS_PARSE_INPUT_H
# include "bonus_index.h"

void		set_id(char *string, t_l_list *node);
void		set_move(char *string, t_l_list *node);
t_l_list	*read_input(t_stack *stacks);
t_l_list	*chose_move(char *string, t_l_list *list, t_stack *stacks);

#endif /* PS_BONUS_PARSE_INPUT_H */
