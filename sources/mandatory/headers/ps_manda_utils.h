/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_manda_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:56:23 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/02 15:58:33 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_MANDA_UTILS_H
# define PS_MANDA_UTILS_H

t_stack	*copy_stacks(t_stack *stack_from);
void copy_stack(int *stack_to, int *stack_from, int length);
#endif /* PS_MANDA_UTILS_H */
