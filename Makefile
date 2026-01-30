# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 11:42:39 by htoe              #+#    #+#              #
#    Updated: 2026/01/30 12:50:02 by htoe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#target
.DEFAULT_GOAL := all

#Compilation & Commands
NAME1 = a.out
CC = cc
CFLAGS = -Wall -Wextra -Werror 
CINCLUDE = -Iinclude -Ilibft/include
LIBFLAGS = -Llibft -lft
RM = rm -Rf

#Directories
SRCDIR = srcs
OBJDIR = objs
OPS = ops
STACKS = stacks
PS = main
CHECKERDIR = checker

#Sources
PS_SRCS = \
	${wildcard ${SRCDIR}/${OPS}/*.c} \
	${wildcard ${SRCDIR}/${STACKS}/*c} \
	${wildcard ${SRCDIR}/${PS}/*c}
PS_OBJS = ${PS_SRCS:${SRCDIR}/%.c=${OBJDIR}/%.o}
LIBS = libft/libft.a

#Pattern Rules

${OBJDIR}/%.o: ${SRCDIR}/%.c Makefile
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} ${CINCLUDE} -c $< -o $@

${LIBS}:
	@echo "COMPILING LIBFT"
	@make -s -C libft

${NAME1}: Makefile ${PS_OBJS} ${LIBS}
	@echo "COMPILING OBJECTS"
	@echo "LINKING OBJECTS"
	@${CC} ${PS_OBJS} ${LIBFLAGS} -o ${NAME1}
	@echo "FINISHED"

all: ${NAME1}

clean:
	@echo "CLEANING"
	@${RM} ${OBJDIR}
#	@make clean -s -C libft

fclean: clean
	@${RM} ${NAME1}
#	@make fclean -s -C libft

re: fclean all

.PHONY: all clean fclean re
