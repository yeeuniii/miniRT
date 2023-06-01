#include "../../include/minirt.h"
#include "../../include/utils.h"
#include <math.h>

static void	get_determinant(t_cylinder cylinder, t_ray ray, t_equation *eq)
{
	t_vector	o_c;
	t_vector	cross_d_e;
	t_vector	cross_oc_e;

	o_c = vector_minus(ray.origin, cylinder.center);
	cross_d_e = vector_cross_product(ray.direct, cylinder.direct);
	cross_oc_e = vector_cross_product(o_c, cylinder.direct);
	eq->a = pow(get_vector_size(cross_d_e), 2);
	eq->b = 2 * vector_inner_product(cross_d_e, cross_oc_e);
	eq->c = pow(get_vector_size(cross_oc_e), 2) - pow(cylinder.radius, 2);
	eq->determinant = eq->b * eq->b - 4 * eq->a * eq->c;
}

int	hit_cylinder_side(t_cylinder cylinder, t_ray ray, t_hitted *record)
{
	t_equation	equation;
	t_vector	hitted_ray;
	double		height;

	get_determinant(cylinder, ray, &equation);
	if (equation.determinant < 0 || !is_hitted(record, &equation))
		return (0);
	hitted_ray = point_ray(ray, equation.root);
	if (!is_in_finite_cylinder(cylinder, hitted_ray, &height))
		return (0);
	record->t = equation.root;
	record->t_max = record->t;
	record->p = hitted_ray;
	record->color = cylinder.color;
	record->normal = get_cylinder_normal(cylinder, record, height);
	set_normal_vector(ray, record);
	return (1);
}

static void	get_root(
		t_cylinder cylinder,
		t_ray ray,
		t_equation *equation,
		t_point center)
{
	equation->p = vector_inner_product(cylinder.direct, ray.direct);
	equation->q = vector_inner_product(cylinder.direct,
			vector_minus(center, ray.origin));
	equation->root = equation->q / equation->p;
}

int	hit_cylinder_circle(
		t_cylinder cylinder,
		t_ray ray,
		t_hitted *record,
		int sign)
{
	t_point		circle_center;
	t_equation	equation;
	t_vector	hitted_ray;
	double		length;

	circle_center = vector_plus(cylinder.center,
			vector_multiple(cylinder.direct, sign * cylinder.height / 2));
	get_root(cylinder, ray, &equation, circle_center);
	hitted_ray = point_ray(ray, equation.root);
	length = get_vector_size(vector_minus(circle_center, hitted_ray));
	if (fabs(equation.p) < EPSILON
		|| length > cylinder.radius
		|| !is_valid_root(equation.root, *record))
		return (0);
	record->t = equation.root;
	record->t_max = record->t;
	record->p = hitted_ray;
	record->color = cylinder.color;
	record->normal = get_unit_vector(vector_multiple(cylinder.direct, sign));
	set_normal_vector(ray, record);
	return (1);
}

int	hit_cylinder(t_object *object, t_ray ray, t_hitted *record)
{
	t_cylinder	cylinder;
	int			is_hitted;

	cylinder = *(t_cylinder *)object;
	is_hitted = 0;
	is_hitted += hit_cylinder_circle(cylinder, ray, record, 1);
	is_hitted += hit_cylinder_circle(cylinder, ray, record, -1);
	is_hitted += hit_cylinder_side(cylinder, ray, record);
	return (is_hitted);
}
