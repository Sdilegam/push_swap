/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:47:48 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/06/09 12:17:27 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_BONUS_UTILS_H
# define PS_BONUS_UTILS_H
# include "bonus_index.h"

int		ft_strcmp(char *s1, char *s2);
void	free_and_exit(void **ptr);
void	free_list(t_l_list *list);
int		ft_find_chara(char *string, int chara);

#endif /* PS_BONUS_UTILS_H */
