#include "../../include/main.h"
#include "../../include/utils.h"

void	test_lights(t_lights *l)
{
	printf("\ncheck ambient\n");
	printf("l_lange %.1f\n", l->ambient.lighting_ratio);
	printf("color %.1f,%.1fd,%.1f\n",
		   l->ambient.color.x, l->ambient.color.y, l->ambient.color.z);
	
	printf("\n\n");

	printf("check camera\n");
	printf("v_point %.f, %.f, %.f \n", l->camera.origin.x, l->camera.origin.y, l->camera.origin.z);
	printf("o_vector_range %.f,%.f,%.f\n", \
		l->camera.direct.x, l->camera.direct.y, l->camera.direct.z);
	printf("fov %.1f\n", l->camera.fov);

	printf("\n\n");

	printf("check light\n");
	printf("l_point %.f,%.f,%.f \n", l->light.origin.x, l->light.origin.y, l->light.origin.z);
	printf("bright_range %.1f\n", l->light.bright_ratio);
	printf("color %.1f,%.1f,%.1f\n", l->light.color.x, l->light.color.y, l->light.color.z);

	printf("\n\n");
}

void	test_shapes(t_object *s)
{
	t_object *tmp;
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
			printf("radius %.1f\n", sphere->radius);
			printf("colors %.1f,%.1f,%.1f\n\n", sphere->color.x, sphere->color.y, sphere->color.z);
		}
		else if (tmp->type == PLANE)
		{
			plane = (t_plane *)tmp->object;
			printf("plane\n");
			printf("p_point %.1f,%.1f,%.1f \n", plane->point.x, plane->point.y, plane->point.z);
			printf("n_vector_range %.1f,%.1f,%.1f \n", plane->normal.x, plane->normal.y, plane->normal.z);
			printf("colors %.1f,%.1f,%.1f\n\n", plane->color.x, plane->color.y, plane->color.z);
		}
		else if (tmp->type == CYLINDER)
		{
			cyl = (t_cylinder *)tmp->object;
			printf("cylinder\n");
			printf("center %.1f,%.1f,%.1f \n", cyl->center.x, cyl->center.y, cyl->center.z);
			printf("vector_axis_range %.1f,%.1f,%.1f \n", cyl->direct.x, cyl->direct.y, cyl->direct.z);
			printf("diameter %.1f\n", cyl->diameter);
			printf("radius %.1f \n", cyl->radius);
			printf("height %.1f \n", cyl->height);
			printf("colors %.1f,%.1f, %.1f\n\n", cyl->color.x, cyl->color.y, cyl->color.z);
		}
		tmp = tmp->next;
	}
}
