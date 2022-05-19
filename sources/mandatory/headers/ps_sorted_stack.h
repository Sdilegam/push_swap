/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorted_stack.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 07:44:25 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/19 06:42:34 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SORTED_STACK_H
# define PS_SORTED_STACK_H
# include "manda_index.h"

t_stack	*copy_stack(t_stack *stack_from);
t_stack	arrange_stack(t_stack *stacks);

#endif /* PS_SORTED_STACK_H */
