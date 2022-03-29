/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:10:20 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/03/29 10:34:29 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 0
# define FALSE -1

struct s_stack
{
	int	*stack;
	int	length;
};

typedef int	t_bool;

t_bool	is_number(char chara);
t_bool	is_space(char chara);

#endif