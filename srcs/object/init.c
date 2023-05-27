#include "../../include/main.h"
#include "../../include/utils.h"
#include <math.h>

void	set_camera(t_camera *camera, t_screen screen)
{
	t_point		origin;
	t_vector	tmp;
	double		tan_fov;

	origin = camera->origin;
	camera->viewport_height = VIEWPORT_HEIGHT;
	camera->viewport_width = camera->viewport_height * screen.aspect_ratio;
	camera->vertical = init_vector(0, 1, 0);
	if (fabs(camera->direct.y) == 1)
		camera->vertical = init_vector(0, 0, 1);
	camera->horizontal = vector_cross_product(camera->vertical, camera->direct);
	camera->horizontal = get_unit_vector(camera->horizontal);
	camera->horizontal = vector_multiple(camera->horizontal, -1);
	tan_fov = tan(camera->fov * M_PI / 360);
	camera->focal_length = camera->viewport_width / 2 / tan_fov;
	tmp = init_vector(0, 0, camera->focal_length);
	camera->left_bottom = vector_minus(origin, tmp);
	tmp = vector_multiple(camera->horizontal, camera->viewport_width / 2);
	camera->left_bottom = vector_minus(camera->left_bottom, tmp);
	tmp = vector_multiple(camera->vertical, camera->viewport_height / 2);
	camera->left_bottom = vector_minus(camera->left_bottom, tmp);
}
