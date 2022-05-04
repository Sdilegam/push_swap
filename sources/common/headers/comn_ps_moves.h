/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comn_ps_moves.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:57:08 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/04 11:13:51 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMN_PS_MOVES_H
# define COMN_PS_MOVES_H
# include "comn_index.h"

void	push(t_stack *stacks, int id);

void	rotate(t_stack *stacks, int id);
void	rotate_both(t_stack *stacks);

void	rev_rotate(t_stack *stacks, int id);
void	rev_rotate_both(t_stack *stacks);

void	swap(t_stack *stacks, int id);
void	swap_both(t_stack *stacks);

#endif
