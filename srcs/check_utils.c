#include "../include/utils.h"

double	check_all_atof(char *str)
{
	int i;
	int	flag;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '0' && str[i + 1] != '.')
		return (0);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (flag == 1)
				error_exit("Too many sign\n");
			flag = 1;
		}
		if (str[i] == '.')
			return (ft_atof(str));
		i++;
	}
	return (ft_atoi(str));
}

t_colors	check_color_argv(char *str)
{
	t_colors	tml;
	int			i;
	char		**dest;

	dest = ft_split(str, ',');
	i = -1;
	while (dest[++i])
	{
		if (!check_space_and_digit(dest[i]))
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