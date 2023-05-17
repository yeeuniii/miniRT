#include "../include/main.h"
#include "../include/utils.h"

void	test_lights(t_lights *l)
{
	printf("check ambient\n");
	printf("l_lange %.1f\n", l->ambient->lighting_ratio);
	printf("color %d,%d,%d\n",
		   l->ambient->color.r, l->ambient->color.g, l->ambient->color.b);
	
	printf("\n\n");

	printf("check camera\n");
	printf("v_point %.f, %.f, %.f \n", l->camera->origin.x, l->camera->origin.y, l->camera->origin.z);
	printf("o_vector_range %.f,%.f,%.f\n", \
		l->camera->direct.x, l->camera->direct.y, l->camera->direct.z);
	printf("fov %d\n", l->camera->fov);

	printf("\n\n");

	printf("check light\n");
	printf("l_point %.f,%.f,%.f \n", l->light->origin.x, l->light->origin.y, l->light->origin.z);
	printf("bright_range %.1f\n", l->light->bright_ratio);
	printf("color %d,%d,%d\n", l->light->color.r, l->light->color.g, l->light->color.b);

	printf("\n\n");
}

void	test_shapes(t_objects *s)
{
	t_objects *tmp;
	t_sphere *sphere;
	t_plane	 *plane;
	t_cylinder *cyl;

	tmp = s;
	while (tmp)
	{
		if (tmp->type == SPHERE)
		{
			sphere = (t_sphere *)tmp->object;
			printf("sphere\n");
			printf("s_center %.1f,%.1f,%.1f \n", sphere->center.x, sphere->center.y, sphere->center.z);
			printf("s_diameter %.1f \n", sphere->diameter);
			printf("colors %d,%d,%d\n\n", sphere->color.r, sphere->color.g, sphere->color.b);
		}
		else if (tmp->type == PLANE)
		{
			plane = (t_plane *)tmp->object;
			printf("plane\n");
			printf("p_point %.1f,%.1f,%.1f \n", plane->point.x, plane->point.y, plane->point.z);
			printf("n_vector_range %.1f,%.1f,%.1f \n", plane->normal.x, plane->normal.y, plane->normal.z);
			printf("colors %d,%d,%d\n\n", plane->color.r, plane->color.g, plane->color.b);
		}
		else if (tmp->type == CYLINDER)
		{
			cyl = (t_cylinder *)tmp->object;
			printf("cylinder\n");
			printf("center %.1f,%.1f,%.1f \n", cyl->center.x, cyl->center.y, cyl->center.z);
			printf("vector_axis_range %.1f,%.1f,%.1f \n", cyl->normal.x, cyl->normal.y, cyl->normal.z);
			printf("diameter %.1f\n", cyl->diameter);
			printf("height %.1f \n", cyl->height);
			printf("colors %d,%d,%d\n\n", cyl->color.r, cyl->color.g, cyl->color.b);
		}
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_lights	lights;
	t_objects	shapes;
	//t_mlx		mlx_info;

	init_argv(ac, av, &lights, &shapes);
	//init_mlx(&mlx_info);
	test_lights(&lights);
	test_shapes(&shapes);
	//mlx_loop(mlx_info.mlx);
	return (0);
}
