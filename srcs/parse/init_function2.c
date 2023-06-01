#include "../../include/minirt.h"
#include "../../include/utils.h"

void	init_camera(t_strs *strs, t_lights *l)
{
	if (check_split_count(strs->s1) != 4)
		error_exit("Wrong camera argc\n", strs, NULL);
	l->camera.origin = atof_vector(strs->s1[1], strs, NULL);
	l->camera.direct = atof_vector(strs->s1[2], strs, NULL);
	if (!check_vector_range(l->camera.direct))
		error_exit("Wrong o_vector_range number\n", strs, NULL);
	l->camera.fov = check_all_atof(strs->s1[3], strs, NULL);
	if (l->camera.fov < 0 || l->camera.fov > 180)
		error_exit("Wrong fov number\n", strs, NULL);
}

void	init_light(t_strs *strs, t_lights *l)
{
	if (check_split_count(strs->s1) != 4)
		error_exit("Wrong light argc\n", strs, NULL);
	l->light.origin = atof_vector(strs->s1[1], strs, NULL);
	l->light.bright_ratio = check_all_atof(strs->s1[2], strs, NULL);
	if (l->light.bright_ratio < 0.0 || l->light.bright_ratio > 1.0)
		error_exit("Incorrectly entered bright range\n", strs, NULL);
	l->light.color = check_color_argv(strs->s1[3], strs, NULL);
}

void	init_sphere(t_strs *strs, t_object *o)
{
	t_sphere	*sphere;

	if (check_split_count(strs->s1) != 4)
		error_exit("Wrong sphere argc\n", strs, o);
	sphere = (t_sphere *)malloc(sizeof(t_sphere) * 1);
	sphere->center = atof_vector(strs->s1[1], strs, o);
	sphere->diameter = check_all_atof(strs->s1[2], strs, o);
	if (sphere->diameter <= 0)
		error_exit("must be greater than 0\n", strs, o);
	sphere->radius = sphere->diameter / 2;
	sphere->color = check_color_argv(strs->s1[3], strs, o);
	init_object(SPHERE, sphere, o);
}

void	init_plane(t_strs *strs, t_object *o)
{
	t_plane		*plane;

	if (check_split_count(strs->s1) != 4)
		error_exit("Wrong plane argc\n", strs, o);
	plane = (t_plane *)malloc(sizeof(t_plane) * 1);
	plane->point = atof_vector(strs->s1[1], strs, o);
	plane->normal = atof_vector(strs->s1[2], strs, o);
	if (!check_vector_range(plane->normal))
		error_exit("Incorrectly entered n_vector range\n", strs, o);
	plane->color = check_color_argv(strs->s1[3], strs, o);
	init_object(PLANE, plane, o);
}

void	init_cylinder(t_strs *strs, t_object *o)
{
	t_cylinder	*cyl;

	if (check_split_count(strs->s1) != 6)
		error_exit("Wrong cylinder argc\n", strs, o);
	cyl = (t_cylinder *)malloc(sizeof(t_cylinder) * 1);
	cyl->center = atof_vector(strs->s1[1], strs, o);
	cyl->direct = atof_vector(strs->s1[2], strs, o);
	if (!check_vector_range(cyl->direct))
		error_exit("Incorrectly entered vector_axis_range\n", strs, o);
	cyl->diameter = check_all_atof(strs->s1[3], strs, o);
	cyl->radius = cyl->diameter / 2;
	cyl->height = check_all_atof(strs->s1[4], strs, o);
	if (cyl->diameter <= 0 || cyl->height <= 0)
		error_exit("must be greater than 0\n", strs, o);
	cyl->color = check_color_argv(strs->s1[5], strs, o);
	init_object(CYLINDER, cyl, o);
}
