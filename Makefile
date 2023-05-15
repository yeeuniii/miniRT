NAME = miniRT
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT = libft.a

SRCS = main.c\
		srcs/get_next_line_utils.c\
		srcs/get_next_line.c\
		srcs/utils.c\
		srcs/init_function.c\
		srcs/init_function2.c\
		srcs/check_utils.c

OBJS = $(SRCS:.c=.o)

all : ${LIBFT} ${NAME}

${LIBFT} :
	make -C ./libft all

${NAME} : ${OBJS}
	# CC ${CFLAGS} ${OBJS} ${LIBFT} -I ./ -lmlx -framework OpenGL -framework AppKit -o ${NAME}
	CC ${CFLAGS} ${OBJS} ${LIBFT} -I ./include -o ${NAME}
clean :
	make -C ./libft clean
	${RM} ${OBJS}

fclean : clean
	make -C ./libft fclean
	${RM} ${NAME}

re :
	make fclean
	make all