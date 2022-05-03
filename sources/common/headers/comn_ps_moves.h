/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comn_ps_moves.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:57:08 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/28 11:06:20 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMN_PS_MOVES_H
# define COMN_PS_MOVES_H
# include "comn_index.h"

void	rotate(t_stack *stacks, int id);
void	rev_rotate(t_stack *stacks, int id);
void	swap(t_stack *stacks, int id);
void	push(t_stack *stacks, int id);

#endif
