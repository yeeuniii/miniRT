#include "../../include/main.h"
#include "../../include/utils.h"

void	init_camera(char **str, t_lights *l)
{
	if (check_split_count(str) != 4)
		error_exit("Wrong camera argc\n", str, NULL, NULL);
	l->camera.origin = atof_vector(str[1], str, NULL);
	l->camera.direct = atof_vector(str[2], str, NULL);
	if (!check_vector_range(l->camera.direct))
		error_exit("Wrong o_vector_range number\n", str, NULL, NULL);
	l->camera.fov = check_all_atof(str[3], str, NULL, NULL);
	if (l->camera.fov < 0 || l->camera.fov > 180)
		error_exit("Wrong fov number\n", str, NULL, NULL);
}

void	init_light(char **str, t_lights *l)
{
	if (check_split_count(str) != 4)
		error_exit("Wrong light argc\n", str, NULL, NULL);
	l->light.origin = atof_vector(str[1], str, NULL);
	l->light.bright_ratio = check_all_atof(str[2], str, NULL, NULL);
	if (l->light.bright_ratio < 0.0 || l->light.bright_ratio > 1.0)
		error_exit("Incorrectly entered bright range\n", str, NULL, NULL);
	l->light.color = check_color_argv(str[3], str, NULL);
}



void	init_sphere(char **str, t_object *o)
{
	t_sphere	*sphere;

	if (check_split_count(str) != 4)
		error_exit("Wrong sphere argc\n", str, NULL, o);
	sphere = (t_sphere *)malloc(sizeof(t_sphere) * 1);
	sphere->center = atof_vector(str[1], str, o);
	sphere->diameter = check_all_atof(str[2], str, NULL, o);
	sphere->color = check_color_argv(str[3], str, o);
	init_object(SPHERE, sphere, o);
}

void	init_plane(char **str, t_object *o)
{
	t_plane		*plane;

	if (check_split_count(str) != 4)
		error_exit("Wrong plane argc\n", str, NULL, o);
	plane = (t_plane *)malloc(sizeof(t_plane) * 1);
	plane->point = atof_vector(str[1], str, o);
	plane->normal = atof_vector(str[2], str, o);
	if (!check_vector_range(plane->normal))
		error_exit("Incorrectly entered n_vector range\n", str, NULL, o);
	plane->color = check_color_argv(str[3], str, o);
	init_object(PLANE, plane, o);
}

void	init_cylinder(char **str, t_object *o)
{
	t_cylinder	*cyl;

	if (check_split_count(str) != 6)
		error_exit("Wrong cylinder argc\n", str, NULL, o);
	cyl = (t_cylinder *)malloc(sizeof(t_cylinder) * 1);
	cyl->center = atof_vector(str[1], str, o);
	cyl->direct = atof_vector(str[2], str, o);
	if (!check_vector_range(cyl->direct))
		error_exit("Incorrectly entered vector_axis_range\n", str, NULL, o);
	cyl->diameter = check_all_atof(str[3], str, NULL, o);
	cyl->height = check_all_atof(str[4], str, NULL, o);
	cyl->color = check_color_argv(str[5], str, o);
	init_object(CYLINDER, cyl, o);
}
