NAME = miniRT
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
CLIB = -lmlx -framework OpenGL -framework AppKit -Imlx
RM = rm -f
LIBFT_DIR = ./libft/
LIBFT = libft.a

SRCS_DIR = srcs/
PARSE_SRCS_DIR = $(SRCS_DIR)parse/
VECTOR_SRCS_DIR = $(SRCS_DIR)vector/
OBJECT_SRCS_DIR = $(SRCS_DIR)object/

SRCS = main.c \
	mlx_init.c \

PARSE_SRCS = \
	get_next_line_utils.c \
	get_next_line.c \
	utils.c \
	utils2.c \
	utils3.c \
	init_function.c \
	init_function2.c \
	check_utils.c \
	error_function.c \
	ft_split2.c \
	test.c

VECTOR_SRCS = \
	calculate.c \
	utils.c \
	ray.c \

OBJECT_SRCS = \
	init.c \
	draw.c \
	hit.c \

OBJS := \
	$(addprefix $(SRCS_DIR), $(SRCS:.c=.o)) \
	$(addprefix $(PARSE_SRCS_DIR), $(PARSE_SRCS:.c=.o)) \
	$(addprefix $(VECTOR_SRCS_DIR), $(VECTOR_SRCS:.c=.o)) \
	$(addprefix $(OBJECT_SRCS_DIR), $(OBJECT_SRCS:.c=.o)) \


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
