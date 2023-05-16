#include "../include/main.h"
#include "../include/utils.h"

void	test_lights(t_lights *l)
{
	printf("check ambient\n");
	printf("identifier %d\n", l->ambient->identifier);
	printf("l_lange %.1f\n", l->ambient->l_range);
	printf("color %d,%d,%d\n",
		   l->ambient->colors.r, l->ambient->colors.g, l->ambient->colors.b);
	
	printf("\n\n");

	printf("check camera\n");
	printf("identifier %d\n", l->camera->identifier);
	printf("v_point %.f, %.f, %.f \n", l->camera->v_point.x, l->camera->v_point.y, l->camera->v_point.z);
	printf("o_vector_range %.f,%.f,%.f\n", \
		l->camera->o_vector_range.x, l->camera->o_vector_range.y, l->camera->o_vector_range.z);
	printf("fov %d\n", l->camera->fov);

	printf("\n\n");

	printf("check light\n");
	printf("identifier %d\n", l->light->identifier);
	printf("l_point %.f,%.f,%.f \n", l->light->l_point.x, l->light->l_point.y, l->light->l_point.z);
	printf("bright_range %.1f\n", l->light->bright_range);
	printf("color %d,%d,%d\n", l->light->colors.r, l->light->colors.g, l->light->colors.b);

	printf("\n\n");
}

void	test_shapes(t_shapes *s)
{
	t_shapes *tmp;
	t_sphere *sphere;
	t_plane	 *plane;
	t_cylinder *cyl;

	tmp = s;
	while (tmp)
	{
		if (tmp->type == sp)
		{
			sphere = (t_sphere *)tmp->shape;
			printf("sphere\n");
			printf("identifier %d\n", sphere->identifier);
			printf("s_center %.1f,%.1f,%.1f \n", sphere->s_center.x, sphere->s_center.y, sphere->s_center.z);
			printf("s_diameter %.1f \n", sphere->s_diameter);
			printf("colors %d,%d,%d\n\n", sphere->colors.r, sphere->colors.g, sphere->colors.b);
		}
		else if (tmp->type == pl)
		{
			plane = (t_plane *)tmp->shape;
			printf("plane\n");
			printf("identifier %d\n", plane->identifier);
			printf("p_point %.1f,%.1f,%.1f \n", plane->p_point.x, plane->p_point.y, plane->p_point.z);
			printf("n_vector_range %.1f,%.1f,%.1f \n", plane->n_vector_range.x, plane->n_vector_range.y, plane->n_vector_range.z);
			printf("colors %d,%d,%d\n\n", plane->colors.r, plane->colors.g, plane->colors.b);
		}
		else if (tmp->type == cy)
		{
			cyl = (t_cylinder *)tmp->shape;
			printf("cylinder\n");
			printf("identifier %d\n", cyl->identifier);
			printf("center %.1f,%.1f,%.1f \n", cyl->center.x, cyl->center.y, cyl->center.z);
			printf("vector_axis_range %.1f,%.1f,%.1f \n", cyl->vector_axis_range.x, cyl->vector_axis_range.y, cyl->vector_axis_range.z);
			printf("diameter %.1f\n", cyl->diameter);
			printf("height %.1f \n", cyl->height);
			printf("colors %d,%d,%d\n\n", cyl->colors.r, cyl->colors.g, cyl->colors.b);
		}
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_lights	lights;
	t_shapes	shapes;

	init_argv(ac, av, &lights, &shapes);
	test_lights(&lights);
	test_shapes(&shapes);
	return (0);
}
