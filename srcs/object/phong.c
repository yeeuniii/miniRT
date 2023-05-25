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
	diffuse = diffuse * lights.light.bright_ratio / 255;
	return (vector_multiple(lights.light.color, diffuse));
}

t_color	apply_ambient(t_lights lights)
{
	double	ambient;

	ambient = lights.light.bright_ratio * lights.ambient.lighting_ratio; 
	return (vector_multiple(init_vector(1, 1, 1), ambient));
}

t_color	apply_phong_model(t_lights lights, t_hitted record)
{
	t_color	ratio;

	ratio = init_vector(0, 0, 0);
	ratio = vector_plus(ratio, apply_diffuse(lights, record));
	ratio = vector_plus(ratio, apply_ambient(lights));
	record.color.x *= ratio.x;
	record.color.y *= ratio.y;
	record.color.z *= ratio.z;
	return (get_min_vector(record.color, init_vector(255, 255, 255)));
}
