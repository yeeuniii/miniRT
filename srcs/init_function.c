#include "../include/main.h"
#include "../include/utils.h"

void	init_argv(int ac, char **av, t_lights *l, t_shapes *s)
{
	int		fd;
	char	*tmp;

	if (ac < 2)
		write(1, "error\n", 6); // 추후 변경
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		write(1, "error\n", 6); // 추후 에러함수로 변경할 것
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		checking_argv(tmp, l, s);
		tmp = get_next_line(fd);
	}
}

void	checking_argv(char *tmp, t_lights *l, t_shapes *s)
{
	char **str;

	str = ft_split(tmp, ' ');
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
		write(1,"error\n", 6); //추후 변경
}

t_vec	atof_vector(char *str)
{
	t_vec tmp;
	char **dest;
	
	dest = ft_split(str, ',');//예외처리 할 것, 프리 할 것
	//tmp = (t_vec *)malloc(sizeof(t_vec) * 1);
	tmp.x = check_all_atof(dest[0]);
	tmp.y = check_all_atof(dest[1]);
	tmp.z = check_all_atof(dest[2]);
	return (tmp);
}

void	init_ambient(char **str, t_lights *l)
{
	t_ambient	*a;
	char		**tmp;

	a = (t_ambient *)malloc(sizeof(t_ambient) * 1);
	a->identifier = A;
	a->l_range = ft_atof(str[1]); // 추후 체킹함수로 변경할 것
	tmp = ft_split(str[2], ','); // 추후 변경할 것
	a->colors.r = ft_atoi(tmp[0]);
	a->colors.g = ft_atoi(tmp[1]);
	a->colors.b = ft_atoi(tmp[2]);
	l->ambient = a;
}
