/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comn_ps_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:20:40 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/06 22:37:09 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMN_PS_UTILS_H
# define COMN_PS_UTILS_H
# include "comn_index.h"

void	print_stack(t_stack *stacks);

t_bool	is_digit(char chara);

t_bool	is_space(char chara);

t_bool	is_sign(char chara);

t_bool	is_in_stack(int element, t_stack stack);

t_bool	get_index(t_stack stack, int item);
int		get_smallest(t_stack stack);
int		get_biggest(t_stack stack);
int		is_sorted(t_stack stack);
#endif
