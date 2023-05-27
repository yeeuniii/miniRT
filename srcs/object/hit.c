#include "../../include/main.h"
#include "../../include/utils.h"
#include <math.h>

int	is_valid_root(double root, t_hitted record)
{
	return (root >= record.t_min && root <= record.t_max);
}

int	(*get_object_function(int type))(t_object *object, t_ray ray, t_hitted *record)
{
	if (type == SPHERE)
		return (hit_sphere);
//	if (object->type == PLANE)
//		return (hit_plane);
	return (hit_sphere);
}

int	hit_object(t_object *object, t_ray ray, t_hitted *record)
{
	return ((get_object_function(object->type))(object->object, ray, record));
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
