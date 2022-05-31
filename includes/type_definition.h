/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_definition.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:55:27 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/29 18:34:02 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_DEFINITION_H
# define TYPE_DEFINITION_H


typedef struct s_lim
{
	int	first;
	int	last;
}	t_lim;

typedef struct s_stack
{
	int		*stack;
	int		length;
	t_lim	lim;
}	t_stack;

typedef struct s_functions
{
	int	(*swap)(t_stack *, int);
	int	(*swap_both)(t_stack *, int);
	int	(*push)(t_stack *, int);
	int	(*rotate)(t_stack *, int);
	int	(*rotate_both)(t_stack *, int);
	int	(*rev_rotate)(t_stack *, int);
	int	(*rev_rotate_both)(t_stack *, int);
}	t_functions;

typedef int (*t_move)(t_stack*, int);

typedef int	t_bool;

#endif
