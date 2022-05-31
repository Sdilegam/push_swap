/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:45:19 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/29 18:45:52 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_BONUS_H
# define TYPEDEF_BONUS_H

typedef struct s_linked_list
{
	int			(*move)(t_stack *, int);
	int			id;
	struct s_linked_list	*next;
}	t_l_list;


#endif /* TYPEDEF_BONUS_H */
