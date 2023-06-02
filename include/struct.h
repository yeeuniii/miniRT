#ifndef STRUCT_H
# define STRUCT_H

# include "vector.h"

typedef struct s_ambient
{
	double	lighting_ratio;
	t_color	color;

}	t_ambient;

typedef struct s_camera
{
	t_point		origin;
	t_vector	direct;
	double		fov;
	double		viewport_height;
	double		viewport_width;
	t_vector	horizontal;
	t_vector	vertical;
	double		focal_length;
	t_point		left_bottom;
}	t_camera;

typedef struct s_light
{
	t_point		origin;
	double		bright_ratio;
	t_color		color;

}	t_light;

typedef struct s_sphere
{
	t_point		center;
	double		diameter;
	double		radius;
	t_color		color;

}	t_sphere;

typedef struct s_plane
{
	t_point		point;
	t_vector	normal;
	t_color		color;

}	t_plane;

typedef struct s_cylinder
{
	t_point		center;
	t_vector	direct;
	double		diameter;
	double		radius;
	double		height;
	t_color		color;

}	t_cylinder;

typedef struct s_strs
{
	char	*str;
	char	**s1;
	char	**s2;

}	t_strs;

typedef struct s_equation
{
	double	a;
	double	b;
	double	c;
	double	p;
	double	q;
	double	determinant;
	double	root;
}	t_equation;

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
