#include "../../includes/vector.h"

t_ray	init_ray(t_point origin, t_vector direct)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direct = direct;
	return (ray);
}

t_point	point_ray(t_ray ray, double t)
{
	return (vector_plus(ray.origin, vector_multiple(ray.direct, t)));
}
