/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:50:51 by yeepark           #+#    #+#             */
/*   Updated: 2023/06/23 17:31:07 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include "../../include/utils.h"
#include <math.h>

void	set_axis_unit_vector(t_camera *camera)
{
	camera->vertical = init_vector(0, 1, 0);
	if (fabs(camera->direct.y) == 1)
		camera->vertical = init_vector(0, 0, 1);
	camera->horizontal = vector_cross_product(camera->vertical, camera->direct);
	camera->horizontal = get_unit_vector(camera->horizontal);
	if (camera->horizontal.x < 0)
		camera->horizontal = vector_multiple(camera->horizontal, -1);
	camera->vertical = vector_cross_product(camera->horizontal, camera->direct);
	camera->vertical = get_unit_vector(camera->vertical);
}

void	set_viewport(t_camera *camera, t_screen screen)
{
	double		radian_fov;

	camera->focal_length = FOCAL_LENGTH;
	radian_fov = convert_degree_to_radians(camera->fov);
	camera->viewport_width = camera->focal_length * tan(radian_fov / 2);
	camera->viewport_height = camera->viewport_width / screen.aspect_ratio;
}

void	set_leftbottom(t_camera *camera)
{
	t_vector	x;
	t_vector	y;
	t_vector	z;
	t_vector	left_bottom;

	x = vector_multiple(camera->horizontal, camera->viewport_width / 2);
	y = vector_multiple(camera->vertical, camera->viewport_height / 2);
	z = vector_multiple(camera->direct, camera->focal_length);
	left_bottom = vector_plus(camera->origin, z);
	left_bottom = vector_minus(left_bottom, x);
	camera->left_bottom = vector_minus(left_bottom, y);
}

void	set_camera(t_camera *camera, t_screen screen)
{
	set_axis_unit_vector(camera);
	set_viewport(camera, screen);
	set_leftbottom(camera);
}

void	adjust_light(t_light *light, t_hitted record)
{
	t_vector	epsilon;

	epsilon = vector_multiple(vector_minus(record.p, light->origin), EPSILON);
	light->origin = vector_plus(light->origin, epsilon);
}
