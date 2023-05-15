# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyoung <junyoung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 11:11:53 by junyoung          #+#    #+#              #
#    Updated: 2023/05/15 18:15:52 by junyoung         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #


SRCS = ft_split.c\
		ft_atoi.c\
		ft_isdigit.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f
NAME = ../libft.a

all : ${NAME}

${NAME} : ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} -include ./libft.h  -o $@ -c $<
	ar rcs ${NAME} $@

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re :
	make fclean
	make all

.PHONY : all clean fclean re