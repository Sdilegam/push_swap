/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:45:13 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/19 17:37:49 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int file_des);
char	*ft_return(char **string);
int		ft_strlen(char *string);
int		ft_find_chara(char *string, int chara);
int		ft_cat(char **static_buff, char **string);
void	*ft_free(char **ptr);
void	*ft_calloc(int number, int size);
#endif
