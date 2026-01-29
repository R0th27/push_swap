# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 11:42:39 by htoe              #+#    #+#              #
#    Updated: 2026/01/29 18:51:14 by htoe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#target
.DEFAULT_GOAL := all

#Compilation & Commands
NAME = a.out
CC = cc
CFLAGS = -Wall -Wextra -Werror 
CINCLUDE = -Iinclude -Ilibft/include
LIBFLAGS = -Llibft -lft
RM = rm -Rf

#Directories
SRCDIR = srcs
OBJDIR = objs

#Sources
SRCS = ${wildcard ${SRCDIR}/*.c}
OBJS = ${SRCS:${SRCDIR}/%.c=${OBJDIR}/%.o}
LIBS = libft/libft.a

#Pattern Rules

${OBJDIR}/%.o: ${SRCDIR}/%.c Makefile
	@echo "COMPILING OBJECTS"
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} ${CINCLUDE} -c $< -o $@

${LIBS}:
	@echo "COMPILING LIBFT"
	@make -s -C libft

${NAME}: Makefile ${OBJS} ${LIBS}
	@echo "LINKING OBJECTS"
	@${CC} ${OBJS} ${LIBFLAGS} -o ${NAME}
	@echo "FINISHED"

all: ${NAME}

clean:
	@echo "CLEANING"
	@${RM} ${OBJDIR}
	@make clean -s -C libft

fclean: clean
	@${RM} ${NAME}
	@make fclean -s -C libft

re: fclean all

.PHONY: all clean fclean re
