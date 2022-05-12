/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorted_Stack.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 07:44:25 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/12 08:00:59 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SORTED_STACK_H
# define PS_SORTED_STACK_H

void	copy_stack(int **stack_to, int *stack_from, int length);
t_stack	arrange_stack(t_stack *stacks);

#endif /* PS_SORTED_STACK_H */
