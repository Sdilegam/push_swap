/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comn_ps_moves.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:57:08 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/16 14:19:40 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMN_PS_MOVES_H
# define COMN_PS_MOVES_H
# include "comn_index.h"

int	push(t_stack *stacks, int id);

int	rotate(t_stack *stacks, int id);
int	rotate_both(t_stack *stacks);

int	rev_rotate(t_stack *stacks, int id);
int	rev_rotate_both(t_stack *stacks);

int	swap(t_stack *stacks, int id);
int	swap_both(t_stack *stacks);

#endif
