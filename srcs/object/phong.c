#include "../../include/main.h"
#include "../../include/utils.h"

t_color	apply_diffuse(t_lights lights, t_hitted record)
{
	double		diffuse;
	t_vector	light_vector;

	light_vector = vector_minus(lights.light.origin, record.p);
	light_vector = get_unit_vector(light_vector);
	diffuse = vector_inner_product(light_vector, record.normal);
	if (diffuse < 0)
		diffuse = 0;
	diffuse = diffuse * lights.light.bright_ratio;
	return (vector_multiple(lights.light.color, diffuse / 255));
}

t_color	apply_ambient(t_lights lights)
{
	double	ambient;

	ambient = lights.light.bright_ratio * lights.ambient.lighting_ratio;
	return (vector_multiple(init_vector(1, 1, 1), ambient));
}

int	is_shadow(t_lights lights, t_object *objects, t_hitted record)
{
	t_vector	light_direct;
	double		light_length;
	t_vector	origin;
	t_ray		light_ray;
	t_hitted	shadow_record;

	light_direct = vector_minus(lights.light.origin, record.p);
	light_length = get_vector_size(light_direct);
	origin = vector_plus(record.p, vector_multiple(record.normal, EPSILON));
	light_ray = init_ray(origin, get_unit_vector(light_direct));
	shadow_record.t_min = 0;
	shadow_record.t_max = light_length;
	return (hit(objects, light_ray, &shadow_record));
}

t_color	apply_color(t_color color, t_color ratio)
{
	color.x *= ratio.x;
	color.y *= ratio.y;
	color.z *= ratio.z;
	return (get_min_vector(color, init_vector(255, 255, 255)));
}

t_color	apply_phong_model(t_lights lights, t_object *objects, t_hitted record)
{
	t_color	ratio;

	ratio = init_vector(0, 0, 0);
	ratio = vector_plus(init_vector(0, 0, 0), apply_ambient(lights));
	if (is_shadow(lights, objects, record))
		return (apply_color(record.color, ratio));
	ratio = vector_plus(ratio, apply_diffuse(lights, record));
	return (apply_color(record.color, ratio));
}
