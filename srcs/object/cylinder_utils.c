/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:50:45 by yeepark           #+#    #+#             */
/*   Updated: 2023/06/02 13:50:46 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include "../../include/vector.h"
#include <math.h>

int	is_in_finite_cylinder(
		t_cylinder cylinder,
		t_point hitted_point,
		double *height)
{
	*height = vector_inner_product(cylinder.direct,
			vector_minus(hitted_point, cylinder.center));
	return (fabs(*height) <= (cylinder.height / 2));
}

t_vector	get_cylinder_normal(
		t_cylinder cylinder,
		t_hitted *record,
		double height)
{
	t_vector	normal;
	t_vector	tmp;

	tmp = vector_multiple(cylinder.direct, height);
	tmp = vector_plus(cylinder.center, tmp);
	normal = vector_minus(record->p, tmp);
	return (get_unit_vector(normal));
}
