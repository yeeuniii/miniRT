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
		is_hitted = hit_sphere(*sphere, ray, record);
	}
	return (is_hitted);
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

int	is_shadow(t_lights lights, t_object *objects, t_hitted record)
{
	t_vector	light_direct;
	double		light_length;
	t_ray		light_ray;
	t_hitted	shadow_record;

	light_direct = vector_minus(lights.light.origin, record.p);
	light_length = get_vector_size(light_direct);
	light_ray = init_ray(vector_plus(record.p, vector_multiple(record.normal, EPSILON)), get_unit_vector(light_direct));
	shadow_record.t_min = 0;
	shadow_record.t_max = light_length;
	return (hit(objects, light_ray, &shadow_record));
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
