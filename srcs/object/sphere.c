#include "../../include/main.h"
#include "../../include/utils.h"
#include <math.h>

int	is_hitted(double a, double b, double determinant, t_hitted *record)
{
	double	root;

	root = (-b - sqrt(determinant)) / (2 * a);
	record->t = root;
	if (is_valid_root(root, *record))
		return (1);
	root = (-b + sqrt(determinant)) / (2 * a);
	record->t = root;
	return (is_valid_root(root, *record));
}

double	get_determinant(t_sphere sphere, t_ray ray, double *a, double *b)
{
	t_vector	o_c;
	double		c;
	double		determinant;
	
	o_c = vector_minus(ray.origin, sphere.center);
	*a = vector_inner_product(ray.direct, ray.direct);
	*b = 2 * vector_inner_product(ray.direct, o_c);
	c = vector_inner_product(o_c, o_c) - sphere.radius * sphere.radius;
	determinant = *b * *b - 4 * *a * c;
	return (determinant);
}

int	hit_sphere(t_object *object, t_ray ray, t_hitted *record)
{
	t_sphere	sphere;
	double		a;
	double		b;
	double		determinant;

	sphere = *(t_sphere *)object;
	determinant = get_determinant(sphere, ray, &a, &b);
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
