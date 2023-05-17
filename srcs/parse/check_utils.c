#include "../../include/utils.h"

double	check_all_atof(char *str)
{
	int i;

	i = 0;
	if (str[i] == '0' && str[i + 1] != '.')
		return (0);
	while (str[i])
	{
		if (!check_sig_double2(str))
			error_exit("Too many sign\n");
		if (!ft_isdigit(str[i]) && (str[i] != '-' && str[i] != '+' && str[i] != '.'))
			error_exit("Incorrectly entered number\n");
		if (str[i] == '.')
			return (ft_atof(str));
		i++;
	}
	return (ft_atoi(str));
}

t_color	check_color_argv(char *str)
{
	t_color	tml;
	int			i;
	char		**dest;

	dest = ft_split(str, ',');
	i = -1;
	while (dest[++i])
	{
		if (!check_digit(dest[i]))
			error_exit("Wrong RGB number\n");
	}
	tml.r = ft_atoi(dest[0]);
	tml.g = ft_atoi(dest[1]);
	tml.b = ft_atoi(dest[2]);
	if ((tml.r < 0 || tml.r > 255) || (tml.g < 0 || tml.g > 255) || \
		(tml.b < 0 || tml.b > 255))
		error_exit("R G B range is only 0~255\n");
	return (tml);
}
