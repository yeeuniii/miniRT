#include "../../include/minirt.h"
#include "../../include/utils.h"
#include <math.h>

int	is_valid_root(double root, t_hitted record)
{
	return (root >= record.t_min && root <= record.t_max);
}

int	is_hitted(t_hitted *record, t_equation *equation)
{
	double	determinant;

	determinant = sqrt(equation->determinant);
	equation->root = (-equation->b - determinant) / (2 * equation->a);
	if (is_valid_root(equation->root, *record))
		return (1);
	equation->root = (-equation->b + determinant) / (2 * equation->a);
	return (is_valid_root(equation->root, *record));
}

void	set_normal_vector(t_ray ray, t_hitted *record)
{
	if (vector_inner_product(ray.direct, record->normal) > 0)
		record->normal = vector_multiple(record->normal, -1);
}
