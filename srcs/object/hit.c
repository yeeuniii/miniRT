#include "../../include/minirt.h"
#include "../../include/utils.h"
#include <math.h>

int	hit_object(t_object *object, t_ray ray, t_hitted *record)
{
	int	(*object_funct)(t_object *object, t_ray ray, t_hitted *record);

	if (object->type == SPHERE)
		object_funct = hit_sphere;
	if (object->type == PLANE)
		object_funct = hit_plane;
	if (object->type == CYLINDER)
		object_funct = hit_cylinder;
	return (object_funct(object->object, ray, record));
}

int	hit(t_object *objects, t_ray ray, t_hitted *record)
{	
	int	is_hitted;

	is_hitted = 0;
	while (objects)
	{
		if (hit_object(objects, ray, record))
		{
			is_hitted = 1;
			record->t_max = record->t;
		}
		objects = objects->next;
	}
	return (is_hitted);
}

t_color	get_color(t_lights lights, t_object *objects, t_ray ray)
{
	t_hitted	record;

	record.t_min = EPSILON;
	record.t_max = INFINITY;
	if (!hit(objects, ray, &record))
		return (init_vector(0, 0, 0));
	return (apply_phong_model(lights, objects, record));
}
