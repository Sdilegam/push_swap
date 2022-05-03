/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comn_ps_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:20:40 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/28 11:06:32 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMN_PS_UTILS_H
# define COMN_PS_UTILS_H
# include "comn_index.h"

void	print_stack(t_stack *stacks);

t_bool	is_digit(char chara);

t_bool	is_space(char chara);

t_bool	is_sign(char chara);

#endif
