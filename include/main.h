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
# define ON_DESTROY 17

# define WIDTH 800
# define HEIGHT 600
# define VIEWPORT_HEIGHT 2.0

typedef struct s_objects t_objects;

typedef enum e_type
{
	SPHERE,
	PLANE,
	CYLINDER

}	t_type;

typedef struct s_lights
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;

}	t_lights;

typedef struct s_objects
{
	int			type;
	void		*object;
	t_objects	*next;

}	t_objects;

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

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_data		data;
	t_screen	screen;
}	t_mlx;


#endif
