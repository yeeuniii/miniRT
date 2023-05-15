#include "../include/main.h"
#include "../include/utils.h"

void	init_camera(char **str, t_lights *l)
{
	t_camera *c;

	c = (t_camera *)malloc(sizeof(t_camera) * 1);
	c->identifier = C;
	c->v_point = atof_vector(str[1]);
	c->o_vector_range = atof_vector(str[2]);//범위 체킹 함수 추가할 것
	c->fov = ft_atoi(str[3]); //범위에 대한 체킹함수 추가할 것	
	l->camera = c;
}

void	init_light(char **str, t_lights *l)
{
	t_light	*light;
	char	**dest;

	dest = ft_split(str[3], ',');
	light = (t_light *)malloc(sizeof(t_light) * 1);
	light->identifier = L;
	light->l_point = atof_vector(str[1]);
	light->bright_range = ft_atof(str[2]);
	light->colors.r = ft_atoi(dest[0]); //추후 컬러체킹 함수로 변경할 것 
	light->colors.g = ft_atoi(dest[1]);
	light->colors.b = ft_atoi(dest[2]);
	l->light = light;
}

void	init_sphere(char **str, t_shapes *s)
{
	t_shapes	*shape;
	t_shapes	*tmp;
	t_sphere	*sphere;
	char		**dest;

	sphere = (t_sphere *)malloc(sizeof(t_sphere) * 1);
	sphere->identifier = sp;
	sphere->s_center = atof_vector(str[1]);
	sphere->s_diameter = ft_atof(str[2]);
	dest = ft_split(str[3], ',');
	sphere->colors.r = ft_atoi(dest[0]);
	sphere->colors.g = ft_atoi(dest[1]);
	sphere->colors.b = ft_atoi(dest[2]);
	tmp = ft_lstlast(s);
	if (!tmp)
	{
		s->type = sp;
		s->shape = (void *)sphere;
		return ;
	}
	shape = (t_shapes *)malloc(sizeof(t_shapes) * 1);
	shape->type = sp;
	shape->shape = (void *)sphere;
	tmp->next = shape;
}

void	init_plane(char **str, t_shapes *s)
{
	t_shapes *shape;
	t_shapes *tmp;
	t_plane	*plane;
	char	**dest;

	plane = (t_plane *)malloc(sizeof(t_plane) * 1);
	plane->identifier = pl;
	plane->p_point = atof_vector(str[1]);
	plane->n_vector_range = atof_vector(str[2]);
	dest = ft_split(str[3], ',');
	plane->colors.r = ft_atoi(dest[0]);
	plane->colors.g = ft_atoi(dest[1]);
	plane->colors.b = ft_atoi(dest[2]);
	tmp = ft_lstlast(s);
	if (!tmp)
	{
		s->type = pl;
		s->shape = (void *)plane;
		return ;
	}
	shape = (t_shapes *)malloc(sizeof(t_shapes) * 1);
	shape->type = pl;
	shape->shape = (void *)plane;
	tmp->next = shape;
}

void	init_cylinder(char **str, t_shapes *s)
{
	t_shapes	*shape;
	t_shapes	*tmp;
	t_cylinder	*cyl;
	char 		**dest;

	cyl = (t_cylinder *)malloc(sizeof(t_cylinder) * 1);
	cyl->identifier = cy;
	cyl->center = atof_vector(str[1]);
	cyl->vector_axis_range = atof_vector(str[2]);
	cyl->diameter = ft_atof(str[3]);
	cyl->height = ft_atof(str[4]);
	dest = ft_split(str[5], ',');
	cyl->colors.r = ft_atoi(dest[0]);
	cyl->colors.g = ft_atoi(dest[1]);
	cyl->colors.b = ft_atoi(dest[2]);
	tmp = ft_lstlast(s);
	if (!tmp)
	{
		s->type = cy;
		s->shape = (void *)cyl;
		return ;
	}
	shape = (t_shapes *)malloc(sizeof(t_shapes) * 1);
	shape->type = cy;
	shape->shape = (void *)cyl;
	tmp->next = shape;

}