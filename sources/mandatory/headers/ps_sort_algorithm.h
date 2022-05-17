/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_algorithm.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:23:00 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/17 15:42:04 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SORT_ALGORITHM_H
# define PS_SORT_ALGORITHM_H

int	sort(t_stack *stacks);
int	print_and_sort(t_stack *stacks);
int find_best(t_stack *stacks);
int	is_sorted(t_stack stack);

#endif /* PS_SORT_ALGORITHM_H */
