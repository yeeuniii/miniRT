/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:50:56 by yeepark           #+#    #+#             */
/*   Updated: 2023/06/02 13:50:57 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include "../../include/utils.h"
#include <math.h>

static void	get_root(t_plane plane, t_ray ray, t_equation *equation)
{
	t_vector	p_o;

	p_o = vector_minus(plane.point, ray.origin);
	equation->p = vector_inner_product(ray.direct, plane.normal);
	equation->q = vector_inner_product(p_o, plane.normal);
	equation->root = equation->q / equation->p;
}

int	hit_plane(t_object *object, t_ray ray, t_hitted *record)
{
	t_plane		plane;
	t_equation	equation;

	plane = *(t_plane *)object;
	get_root(plane, ray, &equation);
	if (fabs(equation.p) < EPSILON
		|| !is_valid_root(equation.root, *record))
		return (0);
	record->t = equation.root;
	record->p = point_ray(ray, equation.root);
	record->color = plane.color;
	record->normal = plane.normal;
	set_normal_vector(ray, record);
	return (1);
}
