# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdi-lega <sdi-lega@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 14:30:28 by sdi-lega          #+#    #+#              #
#    Updated: 2021/10/26 15:10:01 by sdi-lega         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS 	= ft_convert_char.c ft_convert_hexa.c ft_convert_nbr.c ft_convert_ptr.c ft_convert_str.c ft_convert_unsigned.c ft_printf.c utils/number_utils.c utils/string_utils.c utils/utils.c

OBJS 	= ${SRCS:.c=.o}

CC		= gcc

FLAGS	= -I. -Wextra -Werror -Wall

RM		= rm -f

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar -rc ${NAME} ${OBJS}
			ranlib ${NAME}
bonus:		${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

list:
			ar -t ${NAME}
			
.PHONY:		all clean fclean re bonus list