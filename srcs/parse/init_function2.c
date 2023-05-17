#include "../../include/main.h"
#include "../../include/utils.h"

void	init_camera(char **str, t_lights *l)
{
	t_camera *c;

	c = (t_camera *)malloc(sizeof(t_camera) * 1);
	c->origin = atof_vector(str[1]);
	c->direct = atof_vector(str[2]);
	if (!check_vector_range(c->direct))
		error_exit("Wrong o_vector_range number\n");
	c->fov = check_all_atof(str[3]);
	if (c->fov < 0 || c->fov > 180)
		error_exit("Wrong fov number\n");
	l->camera = c;
}

void	init_light(char **str, t_lights *l)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light) * 1);
	light->origin = atof_vector(str[1]);
	light->bright_ratio = check_all_atof(str[2]);
	if (light->bright_ratio < 0.0 || light->bright_ratio > 1.0)
		error_exit("Incorrectly entered bright range\n");
	light->color = check_color_argv(str[3]);
	l->light = light;
}

void	init_sphere(char **str, t_objects *s)
{
	t_objects	*shape;
	t_objects	*tmp;
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere) * 1);
	sphere->center = atof_vector(str[1]);
	sphere->diameter = check_all_atof(str[2]);
	sphere->color = check_color_argv(str[3]);
	tmp = ft_lstlast(s);
	if (!tmp)
	{
		s->type = SPHERE;
		s->object = (void *)sphere;
		return ;
	}
	shape = (t_objects *)malloc(sizeof(t_objects) * 1);
	shape->type = SPHERE;
	shape->object = (void *)sphere;
	tmp->next = shape;
}

void	init_plane(char **str, t_objects *s)
{
	t_objects *shape;
	t_objects *tmp;
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane) * 1);
	plane->point = atof_vector(str[1]);
	plane->normal = atof_vector(str[2]);
	if (!check_vector_range(plane->normal))
		error_exit("Incorrectly entered n_vector range\n");
	plane->color = check_color_argv(str[3]);
	tmp = ft_lstlast(s);
	if (!tmp)
	{
		s->type = PLANE;
		s->object = (void *)plane;
		return ;
	}
	shape = (t_objects *)malloc(sizeof(t_objects) * 1);
	shape->type = PLANE;
	shape->object = (void *)plane;
	tmp->next = shape;
}

void	init_cylinder(char **str, t_objects *s)
{
	t_objects	*shape;
	t_objects	*tmp;
	t_cylinder	*cyl;

	cyl = (t_cylinder *)malloc(sizeof(t_cylinder) * 1);
	cyl->center = atof_vector(str[1]);
	cyl->normal = atof_vector(str[2]);
	if (!check_vector_range(cyl->normal))
		error_exit("Incorrectly entered vector_axis_range\n");
	cyl->diameter = check_all_atof(str[3]);
	cyl->height = check_all_atof(str[4]);
	cyl->color = check_color_argv(str[5]);
	tmp = ft_lstlast(s);
	if (!tmp)
	{
		s->type = CYLINDER;
		s->object = (void *)cyl;
		return ;
	}
	shape = (t_objects *)malloc(sizeof(t_objects) * 1);
	shape->type = CYLINDER;
	shape->object = (void *)cyl;
	tmp->next = shape;
}
