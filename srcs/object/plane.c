#include "../../include/minirt.h"
#include "../../include/utils.h"
#include <math.h>

int	hit_plane(t_object *object, t_ray ray, t_hitted *record)
{
	t_plane		plane;
	t_vector	p_o;
	t_equation	equation;

	plane = *(t_plane *)object;
	p_o = vector_minus(plane.point, ray.origin);
	equation.p = vector_inner_product(ray.direct, plane.normal);
	equation.q = vector_inner_product(p_o, plane.normal);
	equation.root = equation.q / equation.p;
	if (fabs(equation.p) < EPSILON
			|| !is_valid_root(equation.root, *record))
		return (0);
	record->t = equation.root;
	record->p = point_ray(ray, equation.root);
	record->color = plane.color;
	record->normal = plane.normal;
	set_normal_vector(ray, record);
	return (1);
}
