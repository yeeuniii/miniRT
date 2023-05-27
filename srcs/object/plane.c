#include "../../include/main.h"
#include "../../include/utils.h"

int	hit_plane(t_object *object, t_ray ray, t_hitted *record)
{
	t_plane		plane;
	t_vector	p_o;
	double		p;
	double		q;
	double		root;

	plane = *(t_plane *)object;
	p = vector_inner_product(ray.direct, plane.normal);
	p_o = vector_minus(plane.point, ray.origin);
	q = vector_inner_product(p_o, plane.normal);
	if (p < EPSILON)
		return (0);
	root = q / p;
	if (!is_valid_root(root, *record))
		return (0);
	record->t = root;
	record->p = point_ray(ray, root);
	record->normal = plane.normal;
	record->color = plane.color;
	set_normal_vector(ray, record);
	return (1);
}
