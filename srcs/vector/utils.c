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
