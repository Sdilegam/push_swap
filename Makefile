# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 11:25:36 by sdi-lega          #+#    #+#              #
#    Updated: 2022/03/29 10:29:48 by sdi-lega         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#																			   #
#									VARIABLES								   #
#																			   #
################################################################################

NAME			=	push_swap

#####################################
#									#
#			Directories				#
#									#
#####################################

SOURCES_DIR		=	sources/
SUB_DIR			=	mandatory/
OBJECTS_DIR		=	${SOURCES_DIR}${SUB_DIR}objects/
LIB_DIR			=	libraries/

#####################################
#									#
#			Sources & objects		#
#									#
#####################################

SOURCES			=	${NAME}.c#Files to compile#
OBJECTS 		=	${OBJECTS_DIR}${SOURCES:.c=.o}
LIBRARIES		=	#Libraries needed#
EXECUTABLES		=	${NAME} #Modify if other executables needed#

#####################################
#									#
#				OTHERS				#
#									#
#####################################

CC				=	gcc
# CC_FLAGS		=	-Wall -Werror -Wextra -Iincludes 
RM				=	rm -f
SLEEP_TIME		=	0.3
SILENT			=	@
SUFFIX			=	


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

all:					mandatory #bonus#
mandatory:				${OBJECTS_DIR} ${NAME}
bonus:					${OBJECTS_DIR}
			${SILENT} make ${addsuffix _bonus, ${NAME}} SUFFIX=_bonus SUB_DIR=bonus/ 
re:						fclean all

#####################################
#									#
#				COMPILING			#
#									#
#####################################

${OBJECTS_DIR}%.o:	${SOURCES_DIR}${SUB_DIR}%.c
			${SILENT} echo  "\033[K\rCreating \"${@F:.c=.o}\".\c"
			${SILENT} ${CC} ${CC_FLAGS} -c $< -o ${OBJECTS_DIR}${@F:.c=.o}
			${SILENT} sleep ${SLEEP_TIME}

${LIBRARIES}:		
			${SILENT} make -C $(@D)

${NAME}${SUFFIX}:			${OBJECTS} ${LIBRARIES}
			${SILENT} echo "\r\"$@\" executable created\033[K"
			${SILENT} ${CC} $^ -o $@
			${SILENT} sleep ${SLEEP_TIME}

#####################################
#									#
#				CLEANING			#
#									#
#####################################

clean:

			${SILENT} echo "\rRemoving objects files (${notdir ${OBJECTS}}).\033[K\c"
			${SILENT} ${RM} ${OBJECTS}
			${SILENT} sleep ${SLEEP_TIME}

clean_bonus:

			${SILENT} echo "\rSwitching to bonus files.\033[K\c"
			${SILENT} make clean SUFFIX=_bonus SUB_DIR=bonus/
			${SILENT} make clean_exe SUFFIX=_bonus SUB_DIR=bonus/

clean_libs:

			${SILENT} echo "\rRemoving libraries (${notdir ${LIBRARIES}}).\033[K\c"
			${SILENT} ${RM} ${LIBRARIES}
			${SILENT} sleep ${SLEEP_TIME}

clean_exe:

			${SILENT} echo "\rRemoving executables (${notdir ${EXECUTABLES}}).\033[K\c"
			${SILENT} ${RM} ${EXECUTABLES} ${EXECUTABLES}${SUFFIX}
			${SILENT} sleep ${SLEEP_TIME}

fclean:					clean clean_bonus clean_libs clean_exe
			${SILENT} echo "\rEverything removed.\033[K"
				
#####################################
#									#
#			INITIALIZATION			#
#									#
#####################################

${OBJECTS_DIR}:
			mkdir ${OBJECTS_DIR}

start:				
			${SILENT} mkdir -p sources/mandatory/objects
			${SILENT} mkdir -p sources/bonus/objects
			${SILENT} mkdir -p includes
			${SILENT} mkdir -p libraries
			${SILENT} touch -a ${addprefix ${SOURCES_DIR}${SUB_DIR}, ${SOURCES}}

.phony: 	fclean clean clean_bonus clean_libs clean_exe start all mandatory bonus re 
