#include "../../include/vector.h"

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

t_vector	get_direct(int i, int j, t_screen screen, t_lights lights)
{
	double		u;
	double		v;
	t_camera	*camera;
	t_vector	tmp;
	t_vector	direct;

	u = (double)i / (screen.width - 1);
	v = (double)j / (screen.height - 1);
	camera = lights.camera;
	tmp = vector_multiple(camera->horizontal, u);
	direct = vector_plus(ft_camera->left_bottom, tmp);
	tmp = vector_multiple(camera->vertical, v);
	direct = vector_plus(direct, tmp);
	direct = vector_minus(direct, camera->origin);
	return (get_unit_vector(direct));
}

