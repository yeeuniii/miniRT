#include "../../include/main.h"
#include "../../include/utils.h"

int	hit_sphere(t_sphere sphere, t_ray ray, t_hitted *record)
{
	t_vector	o_c;
	double		a;
	double		b;
	double		c;
	double		determinant;

	(void)record;
	o_c = vector_minus(ray.origin, sphere.center);
	a = get_vector_size(ray.direct);
	b = 2 * vector_inner_product(ray.direct, o_c);
	c = get_vector_size(o_c) - sphere.radius * sphere.radius;
	determinant = b * b - 4 * a * c;
	return (determinant >= 0);
}

t_color	hit_object(t_object *object, t_ray ray, t_hitted *record)
{
	int			is_hitted;
	t_sphere	*sphere;

	is_hitted = 0;
	if (object->type == SPHERE)
	{
		sphere = (t_sphere *)object->object;
		is_hitted = hit_sphere(*sphere, ray, record);
	}
	if (!is_hitted)
		return (init_color(0, 0, 0));
	return (sphere->color);	
}

t_color	get_color(t_lights lights, t_object *objects, t_ray ray)
{
	t_hitted	record;
	t_color 	color;

	while (objects)
	{
		color = hit_object(objects, ray, &record);
		objects = objects->next;
	}
	return (color);
}
