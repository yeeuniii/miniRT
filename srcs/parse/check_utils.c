#include "../../include/utils.h"

double	check_all_atof(char *str, char **s1, char **s2, t_object *o)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (str[i] == '0' && str[i + 1] && str[i + 1] != '.')
		error_exit("Incorrectly entered number\n", s1, s2, o);
	while (str[i])
	{
		if (!check_sig_double2(str))
			error_exit("Too many sign\n", s1, s2, o);
		if (!ft_isdigit(str[i]) && \
			(str[i] != '-' && str[i] != '+' && str[i] != '.'))
			error_exit("Incorrectly entered number\n", s1, s2, o);
		if (str[i] == '.')
			flag = 1;
		i++;
	}
	if (flag == 1)
		return (ft_atof(str));
	else
		return (ft_atoi(str));
}

t_color	check_color_argv(char *str, char **s, t_object *o)
{
	t_color	tml;
	int		i;
	char	**dest;

	dest = ft_split(str, ',');
	i = -1;
	while (dest[++i])
	{
		if (!check_digit(dest[i]))
		{
			free_split(dest);
			error_exit("Wrong RGB number\n", s, NULL, o);
		}
	}
	tml.x = ft_atoi(dest[0]);
	tml.y = ft_atoi(dest[1]);
	tml.z = ft_atoi(dest[2]);
	free_split(dest);
	if ((tml.x < 0 || tml.x > 255) || (tml.y < 0 || tml.y > 255) || \
		(tml.z < 0 || tml.z > 255))
		error_exit("R G B range is only 0~255\n", s, NULL, o);
	return (tml);
}
