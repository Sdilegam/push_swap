/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 07:32:36 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/08 06:35:47 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_ERRORS_H
# define PS_ERRORS_H

void	error(void);
void	ft_free_ptr(void **ptr);
void	free_stacks(t_stack **stacks);
void	safe_exit(t_stack **stacks);
#endif /* PS_ERRORS_H */
