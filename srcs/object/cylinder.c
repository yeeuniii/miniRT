#include "../../include/main.h"
#include "../../include/utils.h"
#include <math.h>

static double	get_determinant(
		t_cylinder cylinder,
		t_ray ray,
		double *a,
		double *b)
{
	t_vector	o_c;
	t_vector	cross_d_e;
	t_vector	cross_oc_e;
	double		c;

	o_c = vector_minus(ray.origin, cylinder.center);
	cross_d_e = vector_cross_product(ray.direct, cylinder.direct);
	cross_oc_e = vector_cross_product(o_c, cylinder.direct);
	*a = pow(get_vector_size(cross_d_e), 2);
	*b = 2 * vector_inner_product(cross_d_e, cross_oc_e);
	c = pow(get_vector_size(cross_oc_e), 2) - pow(cylinder.radius, 2);
	return (*b * *b - 4 * *a * c);
}

t_vector	get_cylinder_normal(t_cylinder cylinder, t_hitted *record, double height)
{
	t_vector	normal;
	t_vector	tmp;

	tmp = vector_multiple(cylinder.direct, height);
	tmp = vector_plus(cylinder.center, tmp);
	normal = vector_minus(record->p, tmp);
	return (get_unit_vector(normal));
}

int	is_in_finite_cylinder(t_cylinder cylinder, t_hitted *record)
{
	double	height;

	height = vector_inner_product(cylinder.direct,
			vector_minus(record->p, cylinder.center));
	record->normal = get_cylinder_normal(cylinder, record, height);
	return (fabs(height) <= (cylinder.height / 2));
}

int	hit_cylinder_side(t_cylinder cylinder, t_ray ray, t_hitted *record)
{
	double	a;
	double	b;
	double	determinant;

	determinant = get_determinant(cylinder, ray, &a, &b);
	if (determinant < 0
		|| !is_hitted(a, b, determinant, record))
		return (0);
	record->p = point_ray(ray, record->t);
	if (!is_in_finite_cylinder(cylinder, record))
		return (0);
	record->color = cylinder.color;
	set_normal_vector(ray, record);
	return (1);
}

int	hit_cylinder(t_object *object, t_ray ray, t_hitted *record)
{
	t_cylinder	cylinder;
	int			is_hitted;

	cylinder = *(t_cylinder *)object;
	is_hitted = 0;
//	is_hitted += hit_cylinder_cap(cylinder, ray, record, 1);
//	is_hitted += hit_cylinder_cap(cylinder, ray, record, 0);
	is_hitted += hit_cylinder_side(cylinder, ray, record);
	return (is_hitted);
}
