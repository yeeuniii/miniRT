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
typedef enum e_type
{
	A,
	C,
	L,
	sp,
	pl,
	cy

}	t_type;

typedef struct s_lights
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;

}	t_lights;

typedef struct s_shapes
{
	int				type;
	void			*shape;
	struct s_shapes	*next;

}	t_shapes;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;

}				t_mlx;

#endif