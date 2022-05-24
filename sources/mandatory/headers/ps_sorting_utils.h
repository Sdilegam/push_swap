/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:54:17 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/24 13:55:10 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SORTING_UTILS_H
# define PS_SORTING_UTILS_H

# include "manda_index.h"

t_bool	get_index(t_stack stack, int item);
int		get_smallest(t_stack stack);
int		get_biggest(t_stack stack);
#endif /* PS_SORTING_UTILS_H */
