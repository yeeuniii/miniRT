#include "../../include/main.h"
#include "../../include/utils.h"
#include <math.h>

int	hit_object(t_object *object, t_ray ray, t_hitted *record)
{
	int			is_hitted;
	t_sphere	*sphere;

	is_hitted = 0;
	if (object->type == SPHERE)
	{
		sphere = (t_sphere *)object->object;
		sphere->radius = sphere->diameter / 2;
		is_hitted = hit_sphere(*sphere, ray, record);
	}
	return (is_hitted);
}

int	hit(t_object *objects, t_ray ray, t_hitted *record)
{	
	int			is_hitted;
	t_hitted	object_record;
	
	is_hitted = 0;
	object_record = *record;
	while (objects)
	{
		if (hit_object(objects, ray, &object_record))
		{
			is_hitted = 1;
			object_record.t_max = object_record.t;
			*record = object_record;
		}
		objects = objects->next;
	}
	return (is_hitted);
}

t_color	get_color(t_lights lights, t_object *objects, t_ray ray)
{
	t_hitted	record;

	(void)lights;
	record.t_min = 0;
	record.t_max = INFINITY;
	if (!hit(objects, ray, &record))
		return (init_color(0, 0, 0));
	return (apply_phong_model(lights, record));
}
