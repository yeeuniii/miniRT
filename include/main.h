#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "struct.h"
# include "get_next_line.h"

# define KEY_ESC 53
# define FRONT 87
# define BACK 84
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ON_DESTROY 17

# define WIDTH 800
# define HEIGHT 600
# define VIEWPORT_HEIGHT 4.0
# define EPSILON 0.000001

typedef struct s_object	t_object;

typedef enum e_type
{
	SPHERE,
	PLANE,
	CYLINDER

}	t_type;

typedef struct s_lights
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;

}	t_lights;

typedef struct s_object
{
	int			type;
	void		*object;
	t_object	*next;

}	t_object;

typedef struct s_screen
{
	int		width;
	int		height;
	double	aspect_ratio;
}	t_screen;

typedef struct s_data
{
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_data		data;
	t_screen	screen;
	t_lights	*lights;
	t_object	*object;
}	t_mlx;

typedef struct s_hitted
{
	t_point		p;
	t_vector	normal;
	double		t_min;
	double		t_max;
	double		t;
	t_color		color;
}	t_hitted;

#endif
