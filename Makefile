NAME = miniRT
CFLAGS = -Wall -Wextra -Werror -g3 -O2
#CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -O2
CLIB = -lmlx -framework OpenGL -framework AppKit -Imlx
RM = rm -f
LIBFT_DIR = ./libft/
LIBFT = libft.a
MLX_DIR = ./mlx/
MLX = $(MLX_DIR)/libmlx.a

SRCS_DIR = srcs/
PARSE_SRCS_DIR = $(SRCS_DIR)parse/
VECTOR_SRCS_DIR = $(SRCS_DIR)vector/
OBJECT_SRCS_DIR = $(SRCS_DIR)object/

SRCS = main.c \
	mlx.c \

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

VECTOR_SRCS = \
	calculate.c \
	utils.c \
	ray.c \

OBJECT_SRCS = \
	lights_utils.c \
	draw.c \
	hit.c \
	sphere.c \
	plane.c \
	cylinder.c \
	cylinder_utils.c \
	phong.c \
	utils.c \

OBJS := \
	$(addprefix $(SRCS_DIR), $(SRCS:.c=.o)) \
	$(addprefix $(PARSE_SRCS_DIR), $(PARSE_SRCS:.c=.o)) \
	$(addprefix $(VECTOR_SRCS_DIR), $(VECTOR_SRCS:.c=.o)) \
	$(addprefix $(OBJECT_SRCS_DIR), $(OBJECT_SRCS:.c=.o)) \


all : $(LIBFT) $(MLX) $(NAME)

$(LIBFT) :
	@make -C $(LIBFT_DIR) all

$(MLX) :
	@make -C $(MLX_DIR) all

$(NAME) : $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CLIB) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS)

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re :
	@make fclean
	@make all
