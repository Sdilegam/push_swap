# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 11:25:36 by sdi-lega          #+#    #+#              #
#    Updated: 2022/06/10 14:35:25 by sdi-lega         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#																			   #
#									VARIABLES								   #
#																			   #
################################################################################

NAME				=	push_swap

#####################################
#									#
#			Directories				#
#									#
#####################################


#Common#
COMN_DIR			=	sources/common/
COMN_OBJ_DIR		=	${COMN_DIR}objects/

#Mandatory#
MANDA_DIR			=	sources/mandatory/
MANDA_OBJ_DIR		=	${MANDA_DIR}objects/

#Bonus#
BONUS_DIR			=	sources/bonus/
BONUS_OBJ_DIR		=	${BONUS_DIR}objects/

#Other#
LIB_DIR		=	libraries/

#####################################
#									#
#			Sources & objects		#
#									#
#####################################

#Common#
COMN_SRCS			=	ps_errors.c\
						ps_handle_parameters.c\
						ps_push.c\
						ps_rotate.c\
						ps_stacks_init.c\
						ps_swap.c\
						ps_utils.c\
						ps_is_sorted.c\
						# ps_.c\
						ps_.c\
						ps_.c\

COMN_OBJS			=	${addprefix ${COMN_OBJ_DIR}, ${COMN_SRCS:.c=.o}}
COMN_LIBS			=	ft_printf/libftprintf.a#Libs for common sources

#Mandatory#
MANDA_SRCS			=	ps_manda_utils.c\
						ps_print_push.c\
						ps_print_rotate.c\
						ps_print_swap.c\
						ps_sort_algorithm.c\
						ps_sorting_utils.c\
						push_swap.c\
						ps_get_next_change.c\
						ps_best_start.c

MANDA_OBJS			=	${addprefix ${MANDA_OBJ_DIR}, ${MANDA_SRCS:.c=.o}}
MANDA_LIBS			=	${COMN_LIBS}#Libs for mandatory sources

#Bonus#
BONUS_SRCS			=	push_swap_bonus.c\
						ps_bonus_utils.c\
						ps_bonus_parse_input.c\
						ps_bonus_linked_list.c\
						get_next_line.c\
						get_next_line_utils.c

BONUS_OBJS			=	${addprefix ${BONUS_OBJ_DIR}, ${BONUS_SRCS:.c=.o}}
BONUS_LIBS			=	${COMN_LIBS}#Libs for bonus sources

ALL_LIBS			=	${COMN_LIBS} ${MANDA_LIBS} ${BONUS_LIBS}
DEPENDS				=	${MANDA_OBJS:.o=.d} ${BONUS_OBJS:.o=.d} ${COMN_OBJS:.o=.d}
EXECUTABLES			=	${NAME} checker #Modify if other executables needed#

#####################################
#									#
#				OTHERS				#
#									#
#####################################

CC					=	gcc
COMN_INCLUDE		=	-Iincludes -I${COMN_DIR}headers/ ${addprefix -I, ${addprefix ${LIB_DIR},${dir ${COMN_LIBS}}}}
MANDA_INCLUDE		=	-I${MANDA_DIR}headers/ ${addprefix -I, ${addprefix ${LIB_DIR},${dir ${MANDA_LIBS}}}}
BONUS_INCLUDE		=	-I${BONUS_DIR}headers/ ${addprefix -I, ${addprefix ${LIB_DIR},${dir ${BONUS_LIBS}}}}

CC_FLAGS			=	${COMN_INCLUDE} -MMD #-Wall -Werror -Wextra
RM					=	rm -f
SLEEP_TIME			=	0.1
SILENT				=	@

################################################################################
#																			   #
#										RULES								   #
#																			   #
################################################################################

#####################################
#									#
#				GENERAL				#
#									#
#####################################

all:				mandatory bonus
re:					fclean all

mandatory:			${COMN_OBJ_DIR} ${MANDA_OBJ_DIR} ${NAME}
bonus:				${COMN_OBJ_DIR} ${BONUS_OBJ_DIR} checker

#####################################
#									#
#				COMPILING			#
#									#
#####################################

#OBJECTS#
${COMN_OBJ_DIR}%.o:	${addprefix ${COMN_DIR}, %.c} 
			@ echo  "\rCreating common \"${@F:.c=.o}\" object file.\033[K\c"
			${SILENT} ${CC} ${CC_FLAGS} ${COMN_INCLUDE} -c $< -o ${COMN_OBJ_DIR}${@F:.c=.o} -g
			@ sleep ${SLEEP_TIME}
			
${MANDA_OBJ_DIR}%.o:	${addprefix ${MANDA_DIR}, %.c}
			@ echo  "\rCreating mandatory \"${@F:.c=.o}\" object file.\033[K\c"
			${SILENT} ${CC} ${CC_FLAGS} ${MANDA_INCLUDE} -c $< -o ${MANDA_OBJ_DIR}${@F:.c=.o} -g
			@ sleep ${SLEEP_TIME}
			
${BONUS_OBJ_DIR}%.o:	${addprefix ${BONUS_DIR}, %.c}
			@ echo  "\rCreating bonus \"${@F:.c=.o}\" object file.\033[K\c"
			${SILENT} ${CC} ${CC_FLAGS} ${BONUS_INCLUDE} -c $< -o ${BONUS_OBJ_DIR}${@F:.c=.o} -g
			@ sleep ${SLEEP_TIME}
			
#LIBS#
${addprefix ${LIB_DIR}, ${COMN_LIBS}}:
			@ echo  "\rCreating \"${notdir $@}\".\033[K\c"
			${SILENT} make -sC $(@D)
			@ echo "\rLibrary \"${notdir $@}\" created\033[K"

#EXECUTABLES#
${NAME}:				${OBJECTS_DIR} ${addprefix ${LIB_DIR}, ${MANDA_LIBS}} ${COMN_OBJS} ${MANDA_OBJS}
			@ echo "\r\"$@\" executable created\033[K"
			${SILENT} ${CC} ${COMN_OBJS} ${MANDA_OBJS} -o $@ ${addprefix -L, ${addprefix ${LIB_DIR},${dir ${MANDA_LIBS}}}} ${addprefix -l, ${patsubst lib%.a, %, ${notdir ${MANDA_LIBS}}}} -g
			@ sleep ${SLEEP_TIME}
			
checker:			${BONUS_OBJECTS_DIR} ${addprefix ${LIB_DIR}, ${BONUS_LIBS}} ${COMN_OBJS} ${BONUS_OBJS}
			@ echo "\r\"$@\" executable created\033[K"
			${SILENT} ${CC} ${COMN_OBJS} ${BONUS_OBJS} -o $@ ${addprefix -L, ${addprefix ${LIB_DIR},${dir ${BONUS_LIBS}}}} ${addprefix -l, ${patsubst lib%.a, %, ${notdir ${BONUS_LIBS}}}}
			@ sleep ${SLEEP_TIME}

			
-include ${DEPENDS}

#####################################
#									#
#				CLEANING			#
#									#
#####################################

clean:
			@ echo "\rRemoving objects files (${notdir ${COMN_OBJS}} ${notdir ${MANDA_OBJS}}).\033[K\c"
			${SILENT} ${RM} ${OBJECTS} ${COMN_OBJS} ${MANDA_OBJS} ${DEPENDS}
			@ sleep ${SLEEP_TIME}

clean_bonus:
			@ echo "\rRemoving bonnus objects files (${notdir ${BONUS_OBJS}}).\033[K\c"
			${SILENT} ${RM} ${BONUS_OBJS} #${DEPENDS}
			@ sleep ${SLEEP_TIME}

${addprefix clean_,${dir ${COMN_LIBS}}}:
			@ echo "\rRemoving libraries (${patsubst clean_%,%, $@}).\033[K\c"
			${SILENT} make fclean -sC ${patsubst clean_%, libraries/%, $@}
			@ sleep ${SLEEP_TIME}

clean_exe:
			@ echo "\rRemoving executables (${notdir ${EXECUTABLES}}).\033[K\c"
			${SILENT} ${RM} ${EXECUTABLES}
			@ sleep ${SLEEP_TIME}

fclean:			clean ${addprefix clean_,${dir ${ALL_LIBS}}} clean_exe clean_bonus
			${SILENT} rmdir ${MANDA_OBJ_DIR} ${BONUS_OBJ_DIR} ${COMN_OBJ_DIR}
			@ echo "\rEverything removed.\033[K"
				
#####################################
#									#
#			INITIALIZATION			#
#									#
#####################################

${COMN_OBJ_DIR}:
			${SILENT} mkdir ${COMN_OBJ_DIR}
${BONUS_OBJ_DIR}:
			${SILENT} mkdir ${BONUS_OBJ_DIR}
${MANDA_OBJ_DIR}:
			${SILENT} mkdir ${MANDA_OBJ_DIR}

start:				
			${SILENT} mkdir -p sources/common/objects
			${SILENT} mkdir -p sources/common/headers
			${SILENT} mkdir -p sources/mandatory/objects
			${SILENT} mkdir -p sources/mandatory/headers
			${SILENT} mkdir -p sources/bonus/objects
			${SILENT} mkdir -p sources/bonus/headers
			${SILENT} mkdir -p libraries

.phony: 	fclean clean clean_bonus clean_libs clean_exe start all mandatory bonus re 

