#include "../../include/main.h"
#include "../../include/utils.h"

t_color	apply_diffuse(t_lights lights, t_hitted record)
{
	double		diffuse;
	t_vector	light_vector;
	t_color	light_color;

	light_vector = vector_minus(lights.light.origin, record.p);
	light_vector = get_unit_vector(light_vector);
	diffuse = vector_inner_product(light_vector, record.normal);
	if (diffuse < 0)
		diffuse = 0;
	light_color.x = (double)lights.light.color.x / 255;
	light_color.y = (double)lights.light.color.y / 255;
	light_color.z = (double)lights.light.color.z / 255;
	return (vector_multiple(light_color, diffuse * lights.light.bright_ratio));
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
	ratio = vector_plus(ratio, apply_ambient(lights));
	ratio = vector_plus(ratio, apply_diffuse(lights, record));
	ratio.x *= record.color.x;
	ratio.y *= record.color.y;
	ratio.z *= record.color.z;
	return (vector_multiple(ratio, 255));
}
