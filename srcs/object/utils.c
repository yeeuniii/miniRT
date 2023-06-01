#include "../../include/main.h"
#include "../../include/utils.h"
#include <math.h>

int	is_valid_root(double root, t_hitted record)
{
	return (root >= record.t_min && root <= record.t_max);
}

int	is_hitted(
		double a,
		double b,
		double determinant,
		t_hitted *record,
		double *root)
{
	*root = (-b - sqrt(determinant)) / (2 * a);
	if (is_valid_root(*root, *record))
		return (1);
	*root = (-b + sqrt(determinant)) / (2 * a);
	if (is_valid_root(*root, *record))
		return (1);
	return (0);
}

void	set_normal_vector(t_ray ray, t_hitted *record)
{
	if (vector_inner_product(ray.direct, record->normal) > 0)
		record->normal = vector_multiple(record->normal, -1);
}

int	(*get_object_function(int type))(
	t_object *object, t_ray ray, t_hitted *record)
{
	if (type == SPHERE)
		return (hit_sphere);
	if (type == PLANE)
		return (hit_plane);
	return (hit_sphere);
}
