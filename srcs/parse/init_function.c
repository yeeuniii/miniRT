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
		error_exit("Wrong argv\n", NULL, NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_exit("File open error\n", NULL, NULL);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		checking_argv(tmp, l, o);
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
}

void	checking_argv(char *tmp, t_lights *l, t_object *o)
{
	t_strs	strs;

	strs.s1 = ft_split2(tmp);
	if (!strs.s1[0])
	{
		free_split(strs.s1);
		return ;
	}
	if (ft_strcmp(strs.s1[0], "A") == 0)
		init_ambient(&strs, l);
	else if (ft_strcmp(strs.s1[0], "C") == 0)
		init_camera(&strs, l);
	else if (ft_strcmp(strs.s1[0], "L") == 0)
		init_light(&strs, l);
	else if (ft_strcmp(strs.s1[0], "sp") == 0)
		init_sphere(&strs, o);
	else if (ft_strcmp(strs.s1[0], "pl") == 0)
		init_plane(&strs, o);
	else if (ft_strcmp(strs.s1[0], "cy") == 0)
		init_cylinder(&strs, o);
	else
		error_exit("Wrong type\n", &strs, o);
	free_split(strs.s1);
}

t_vector	atof_vector(char *str, t_strs *strs, t_object *o)
{
	t_vector	tmp;

	strs->s2 = ft_split(str, ',');
	tmp.x = check_all_atof(strs->s2[0], strs, o);
	tmp.y = check_all_atof(strs->s2[1], strs, o);
	tmp.z = check_all_atof(strs->s2[2], strs, o);
	free_split(strs->s2);
	return (tmp);
}

void	init_ambient(t_strs *strs, t_lights *l)
{
	if (check_split_count(strs->s1) != 3)
		error_exit("Wrong ambient argc\n", strs, NULL);
	l->ambient.lighting_ratio = check_all_atof(strs->s1[1], strs, NULL);
	if (l->ambient.lighting_ratio < 0 || l->ambient.lighting_ratio > 1.0)
		error_exit("lighting_ratio only 0.0~1.0\n", strs, NULL);
	l->ambient.color = check_color_argv(strs->s1[2], strs, NULL);
}
