/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_algorithm.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:23:00 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/24 13:58:44 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SORT_ALGORITHM_H
# define PS_SORT_ALGORITHM_H

int	sort(t_stack *stacks, t_functions f);
int	get_next_change(t_stack *stacks);
int	find_best(t_stack *stacks);
int	is_sorted(t_stack stack);
int	check_item(int start, t_stack stack);
t_functions	get_functions(int id);
int	move_to(int steps, t_stack *stack, t_functions f);
#endif /* PS_SORT_ALGORITHM_H */
