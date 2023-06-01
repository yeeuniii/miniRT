#include "../../include/main.h"
#include "../../include/utils.h"
#include <math.h>

static double	get_determinant(
		t_sphere sphere,
		t_ray ray,
		double *a,
		double *b)
{
	t_vector	o_c;
	double		c;

	o_c = vector_minus(ray.origin, sphere.center);
	*a = vector_inner_product(ray.direct, ray.direct);
	*b = 2 * vector_inner_product(ray.direct, o_c);
	c = vector_inner_product(o_c, o_c) - sphere.radius * sphere.radius;
	return (*b * *b - 4 * *a * c);
}

int	hit_sphere(t_object *object, t_ray ray, t_hitted *record)
{
	t_sphere	sphere;
	double		a;
	double		b;
	double		determinant;
	double		root;

	sphere = *(t_sphere *)object;
	determinant = get_determinant(sphere, ray, &a, &b);
	if (determinant < 0)
		return (0);
	if (!is_hitted(a, b, determinant, record, &root))
		return (0);
	record->t = root;
	record->p = point_ray(ray, record->t);
	record->normal = get_unit_vector(vector_minus(record->p, sphere.center));
	record->color = sphere.color;
	set_normal_vector(ray, record);
	return (1);
}
