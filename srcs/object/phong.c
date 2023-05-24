#include "../../include/main.h"
#include "../../include/utils.h"

t_color_ratio	apply_ambient(t_lights lights)
{
	double	ambient;

	ambient = lights.light.bright_ratio * lights.ambient.lighting_ratio; 
	return (vector_multiple(init_vector(1, 1, 1), ambient));
}

t_color	apply_phong_model(t_lights lights, t_hitted record)
{
	t_color_ratio	ratio;

	ratio = init_vector(0, 0, 0);
	ratio = vector_plus(ratio, apply_ambient(lights));
	record.color.r *= ratio.x;
	record.color.g *= ratio.y;
	record.color.b *= ratio.z;
	return (record.color);
}
