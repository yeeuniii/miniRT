#include "../../include/main.h"
#include "../../include/utils.h"

void	init_argv(int ac, char **av, t_lights *l, t_objects *s)
{
	int		fd;
	char	*tmp;

	if (ac != 2)
		error_exit("Wrong argv\n");
	s->type = -1;
	s->object = NULL;
	s->next = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_exit("File open error\n");
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		checking_argv(tmp, l, s);
		tmp = get_next_line(fd);
	}
}

void	checking_argv(char *tmp, t_lights *l, t_objects *s)
{
	char **str;

	str = ft_split2(tmp);
	if (!str[0])
		return ;
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
		error_exit("Wrong type\n");
}

t_vector	atof_vector(char *str)
{
	t_vector	tmp;
	char		**dest;
	int			i;
	
	dest = ft_split(str, ',');
	tmp.x = check_all_atof(dest[0]);
	tmp.y = check_all_atof(dest[1]);
	tmp.z = check_all_atof(dest[2]);
	i = -1;
	while (dest[++i])
		free(dest[i]);
	return (tmp);
}

void	init_ambient(char **str, t_lights *l)
{
	t_ambient	*a;

	a = (t_ambient *)malloc(sizeof(t_ambient) * 1);
	a->lighting_ratio = check_all_atof(str[1]);
	if (a->lighting_ratio < 0 || a->lighting_ratio > 1.0)
		error_exit("lighting_ratio only 0.0~1.0\n"); 
	a->color = check_color_argv(str[2]);
	l->ambient = a;
}
