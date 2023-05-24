#include "../../include/main.h"
#include "../../include/utils.h"

t_color	apply_diffuse(t_lights lights, t_hitted record)
{
	double		diffuse;
	t_vector	light_vector;
//	t_color		diffuse_color;

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
//	ambient = lights.ambient.lighting_ratio; 
	return (vector_multiple(init_vector(1, 1, 1), ambient));
}

t_vector	get_min_vector(t_vector vec1, t_vector vec2)
{
	t_vector	new;

	new = vec1;
	if (vec1.x > vec2.x)
		new.x = vec2.x;
	if (vec1.y > vec2.y)
		new.y = vec2.y;
	if (vec1.z > vec2.z)
		new.z = vec2.z;
	return (new);
}

t_color	apply_phong_model(t_lights lights, t_hitted record)
{
	t_color	ratio;

	ratio = init_vector(0, 0, 0);
	ratio = vector_plus(ratio, apply_diffuse(lights, record));
	ratio = vector_plus(ratio, apply_ambient(lights));
	ratio.x *= record.color.x;
	ratio.y *= record.color.y;
	ratio.z *= record.color.z;
	ratio = get_min_vector(ratio, init_vector(255, 255, 255));
	return (ratio);
//	ratio.x *= record.color.x / 255;
//	ratio.y *= record.color.y / 255;
//	ratio.z *= record.color.z / 255;
//	ratio = get_min_vector(ratio, init_vector(1, 1, 1));
//	return (vector_multiple(ratio, 255));
}
