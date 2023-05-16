NAME = miniRT
CFLAGS = -Wall -Wextra -Werror
#CLIB = -Lmlx -lmlx -framework OpenGL -framework AppKit -Imlx
RM = rm -f
LIBFT_DIR = ./libft/
LIBFT = libft.a

SRCS_DIR = srcs/
PARSE_SRCS_DIR = $(SRCS_DIR)parse/

SRCS = main.c 
PARSE_SRCS = \
	get_next_line_utils.c \
	get_next_line.c \
	utils.c \
	utils2.c \
	init_function.c \
	init_function2.c \
	check_utils.c \
	error_function.c \

OBJS := \
	$(addprefix $(SRCS_DIR), $(SRCS:.c=.o)) \
	$(addprefix $(PARSE_SRCS_DIR), $(PARSE_SRCS:.c=.o)) \


all : ${LIBFT} ${NAME}

${LIBFT} :
	@make -C $(LIBFT_DIR) all

${NAME} : ${OBJS} $(LIBFT)
	@$(CC) $(CLIB) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make -C $(LIBFT_DIR) clean
	@${RM} ${OBJS}

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	@${RM} ${NAME}

re :
	@make fclean
	@make all
