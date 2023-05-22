#include "../../include/main.h"
#include "../../include/utils.h"

t_object *init_object_start(void)
{
	t_object *o;

	o = (t_object *)malloc(sizeof(t_object) * 1);
	o->type = -1;
	o->object = NULL;
	o->next = NULL;
	return (o);
}

void	init_argv(int ac, char **av, t_lights *l, t_object *o)
{
	int		fd;
	char	*tmp;

	if (ac != 2)
		error_exit("Wrong argv\n", NULL, NULL, NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_exit("File open error\n", NULL, NULL, NULL);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		checking_argv(tmp, l, o);
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
}

void	checking_argv(char *tmp, t_lights *l, t_object *s)
{
	char	**str;

	str = ft_split2(tmp);
	if (!str[0])
	{
		free_split(str);
		return ;
	}
	if (ft_strcmp(str[0], "A") == 0)
		init_ambient(str, l);
	else if (ft_strcmp(str[0], "C") == 0)
		init_camera(str, l);
	else if (ft_strcmp(str[0], "L") == 0)
		init_light(str, l);
	else if (ft_strcmp(str[0], "sp") == 0)
		init_sphere(str, s);
	else if (ft_strcmp(str[0], "pl") == 0)
		init_plane(str, s);
	else if (ft_strcmp(str[0], "cy") == 0)
		init_cylinder(str, s);
	else
		error_exit("Wrong type\n", str, NULL, s);
	free_split(str);
}

t_vector	atof_vector(char *str, char **s1, t_object *o)
{
	t_vector	tmp;
	char		**dest;

	dest = ft_split(str, ',');
	tmp.x = check_all_atof(dest[0], s1, dest, o);
	tmp.y = check_all_atof(dest[1], s1, dest, o);
	tmp.z = check_all_atof(dest[2], s1, dest, o);
	free_split(dest);
	return (tmp);
}

void	init_ambient(char **str, t_lights *l)
{

	l->ambient.lighting_ratio = check_all_atof(str[1], str, NULL, NULL);
	if (l->ambient.lighting_ratio < 0 || l->ambient.lighting_ratio > 1.0)
		error_exit("lighting_ratio only 0.0~1.0\n", str, NULL, NULL);
	l->ambient.color = check_color_argv(str[2], str, NULL);
}
