#include "../../include/utils.h"

int	check_int_size(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i + 1] == '.')
			break ;
	}
	if ((str[0] == '-' && i > 11) || i > 10)
		return (0);
	else
		return (1);
}

double	check_int_max(char *str, int flag, t_strs *strs, t_object *o)
{
	long long	tmp;
	double		dtmp;

	if (flag == 1)
	{
		dtmp = ft_atof(str);
		if (dtmp > 2147483647 || dtmp < -2147483648)
			error_exit("Only within the range of int", strs, o);
		else
			return (dtmp);
	}
	tmp = ft_atoi(str);
	if (tmp > 2147483647 || tmp < -2147483648)
		error_exit("Only within the range of int", strs, o);
	return (tmp);
}

double	check_all_atof(char *str, t_strs *strs, t_object *o)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (str[i] == '0' && str[i + 1] && str[i + 1] != '.')
		error_exit("Incorrectly entered number\n", strs, o);
	if (!check_sig_double2(str))
		error_exit("Too many sign\n", strs, o);
	if (!check_int_size(str))
		error_exit("Only within the range of int", strs, o);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && \
			(str[i] != '-' && str[i] != '+' && str[i] != '.'))
			error_exit("Incorrectly entered number\n", strs, o);
		if (str[i] == '.')
			flag = 1;
		i++;
	}
	return (check_int_max(str, flag, strs, o));
}

t_color	check_color_argv(char *str, t_strs *strs, t_object *o)
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
			error_exit("Wrong RGB number\n", strs, o);
		}
	}
	tml.x = ft_atoi(dest[0]);
	tml.y = ft_atoi(dest[1]);
	tml.z = ft_atoi(dest[2]);
	free_split(dest);
	if ((tml.x < 0 || tml.x > 255) || (tml.y < 0 || tml.y > 255) || \
		(tml.z < 0 || tml.z > 255))
		error_exit("R G B range is only 0~255\n", strs, o);
	return (tml);
}
