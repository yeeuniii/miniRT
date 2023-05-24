#include "../../include/main.h"
#include "../../include/utils.h"
#include <math.h>

int	is_valid_root(double root, t_hitted record)
{
	return (root >= record.t_min && root <= record.t_max);
}

int	is_hitted(double a, double b, double determinant, t_hitted *record)
{
	double	root;

	root = (-b - determinant) / (2 * a);
	record->t = root;
	if (is_valid_root(root, *record))
		return (1);
	root = (-b + determinant) / (2 * a);
	record->t = root;
	return (is_valid_root(root, *record));
}

int	hit_sphere(t_sphere sphere, t_ray ray, t_hitted *record)
{
	t_vector	o_c;
	double		a;
	double		b;
	double		c;
	double		determinant;

	o_c = vector_minus(ray.origin, sphere.center);
	a = vector_inner_product(ray.direct, ray.direct);
	b = 2 * vector_inner_product(ray.direct, o_c);
	c = vector_inner_product(o_c, o_c) - sphere.radius * sphere.radius;
	determinant = b * b - 4 * a * c;
	if (determinant < 0)
		return (0);
	if (!is_hitted(a, b, determinant, record))
		return (0);
	record->p = point_ray(ray, record->t);
	record->normal = get_unit_vector(vector_minus(record->p, sphere.center));
	record->color = sphere.color;
	if (vector_inner_product(ray.origin, record->normal) > 0)
		record->normal = vector_multiple(record->normal, -1);
	return (1);
}
