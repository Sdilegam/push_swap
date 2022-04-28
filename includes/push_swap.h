/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:10:20 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/28 10:10:20 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "includes_index.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

t_bool	is_digit(char chara);
t_bool	is_sign(char chara);
t_bool	is_space(char chara);

void	rotate(t_stack *stacks, int id);
void	rev_rotate(t_stack *stacks, int id);
void	swap(t_stack *stacks, int id);
void	push(t_stack *stacks, int id);

void	print_stack(t_stack *stacks);
t_stack	arrange_stack(t_stack *stacks);

int		sort(t_stack *stacks, t_stack landmark);
#endif