/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_definition.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:55:27 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/16 10:26:53 by sdi-lega         ###   ########.fr       */
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


typedef int	t_bool;

#endif
