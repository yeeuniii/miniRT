/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:51:24 by yeepark           #+#    #+#             */
/*   Updated: 2023/06/02 13:51:28 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vector.h"
#include <math.h>

t_vector	init_vector(double x, double y, double z)
{
	t_vector	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

void	set_vector(t_vector *vector, double x, double y, double z)
{
	vector->x = x;
	vector->y = y;
	vector->z = z;
}

double	get_vector_size(t_vector vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_vector	get_unit_vector(t_vector vec)
{
	double	size;

	size = get_vector_size(vec);
	return (vector_multiple(vec, 1 / size));
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
