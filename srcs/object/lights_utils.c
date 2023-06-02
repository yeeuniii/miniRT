/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:50:51 by yeepark           #+#    #+#             */
/*   Updated: 2023/06/02 15:29:08 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include "../../include/utils.h"
#include <math.h>

void	set_camera(t_camera *camera, t_screen screen)
{
	t_point		origin;
	t_vector	tmp;
	double		tan_fov;

	origin = camera->origin;
	camera->vertical = init_vector(0, 1, 0);
	if (fabs(camera->direct.y) == 1)
		camera->vertical = init_vector(0, 0, 1);
	camera->horizontal = vector_cross_product(camera->vertical, camera->direct);
	camera->horizontal = get_unit_vector(camera->horizontal);
	if (camera->horizontal.x < 0)
		camera->horizontal = vector_multiple(camera->horizontal, -1);
	camera->focal_length = FOCAL_LENGTH;
	tan_fov = tan(camera->fov * M_PI / 360);
	camera->viewport_width = camera->focal_length * tan_fov;
	camera->viewport_height = camera->viewport_width / screen.aspect_ratio;
	tmp = vector_multiple(camera->direct, camera->focal_length);
	camera->left_bottom = vector_plus(origin, tmp);
	tmp = vector_multiple(camera->horizontal, camera->viewport_width / 2);
	camera->left_bottom = vector_minus(camera->left_bottom, tmp);
	tmp = vector_multiple(camera->vertical, camera->viewport_height / 2);
	camera->left_bottom = vector_minus(camera->left_bottom, tmp);
}

void	adjust_light(t_light *light, t_hitted record)
{
	t_vector	epsilon;

	epsilon = vector_multiple(vector_minus(record.p, light->origin), EPSILON);
	light->origin = vector_plus(light->origin, epsilon);
}
