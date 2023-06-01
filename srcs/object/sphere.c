#include "../../include/minirt.h"
#include "../../include/utils.h"
#include <math.h>

static void	get_determinant(t_sphere sphere, t_ray ray,	t_equation *eq)
{
	t_vector	o_c;

	o_c = vector_minus(ray.origin, sphere.center);
	eq->a = vector_inner_product(ray.direct, ray.direct);
	eq->b = 2 * vector_inner_product(ray.direct, o_c);
	eq->c = vector_inner_product(o_c, o_c) - sphere.radius * sphere.radius;
	eq->determinant = eq->b * eq->b - 4 * eq->a * eq->c;
}

int	hit_sphere(t_object *object, t_ray ray, t_hitted *record)
{
	t_sphere	sphere;
	t_equation	equation;

	sphere = *(t_sphere *)object;
	get_determinant(sphere, ray, &equation);
	if (equation.determinant < 0)
		return (0);
	if (!is_hitted(record, &equation))
		return (0);
	record->t = equation.root;
	record->p = point_ray(ray, record->t);
	record->color = sphere.color;
	record->normal = get_unit_vector(vector_minus(record->p, sphere.center));
	set_normal_vector(ray, record);
	return (1);
}
