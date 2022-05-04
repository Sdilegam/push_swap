/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manda_ps_print_moves.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:44:05 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/04 11:13:15 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDA_PS_PRINT_MOVES_H
# define MANDA_PS_PRINT_MOVES_H

# include "manda_index.h"

void	print_push(t_stack *stacks, int id);

void	print_rotate(t_stack *stacks, int id);
void	print_rotate_both(t_stack *stacks);

void	print_rev_rotate(t_stack *stacks, int id);
void	print_rev_rotate_both(t_stack *stacks);

void	print_swap(t_stack *stacks, int id);
void	print_swap_both(t_stack *stacks);

#endif /* MANDA_PS_PRINT_MOVES_H */
