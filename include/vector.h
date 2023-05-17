#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector	t_vector;
typedef struct s_vector	t_point;

struct s_vector
{
	double	x;
	double	y;
	double	z;

};

typedef struct	s_ray
{
	t_point		origin;
	t_vector	direct;
}	t_ray;

t_vector	init_vector(double x, double y, double z);
void		set_vector(t_vector *vector, double x, double y, double z);
double		get_vector_size(t_vector vec);
t_vector 	get_unit_vector(t_vector vec);
t_vector	vector_plus(t_vector v1, t_vector v2);
t_vector	vector_minus(t_vector v1, t_vector v2);
t_vector	vector_multiple(t_vector vec, double r);
double		vector_inner_product(t_vector v1, t_vector v2);
t_vector	vector_cross_product(t_vector v1, t_vector v2);

t_ray		init_ray(t_point origin, t_vector direct);
t_point		point_ray(t_ray ray, double t);

#endif
