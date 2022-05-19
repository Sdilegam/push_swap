/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:08:45 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/05/19 07:50:41 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manda_index.h"

int	print_push(t_stack *stacks, int id)
{
	ft_printf("p%c\n", 'a' + id);
	return(push(stacks, id));
}
