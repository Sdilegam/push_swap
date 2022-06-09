/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_algorithm.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:23:00 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/09 19:15:34 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SORT_ALGORITHM_H
# define PS_SORT_ALGORITHM_H

int			sort(t_stack *stacks, t_functions f);
t_moves		get_next_change(t_stack *stacks);
int			find_best(t_stack *stacks);
int			is_sorted(t_stack stack);
t_bool		check_item_out(int number, int index, t_stack stack);
t_functions	get_functions(int id);
int			move_to(t_moves steps, t_stack *stack, t_functions f);
#endif /* PS_SORT_ALGORITHM_H */
