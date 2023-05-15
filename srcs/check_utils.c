#include "../include/utils.h"

double	check_all_atof(char *str)
{
	int i;

	if (str[0] == '0')
		return (0);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '.')
			return (ft_atof(str));
	}	
	//기능 추가할 것
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
		{
			write(1, "error1\n", 6); //추후 변경
			exit(1);
		}
	}
	tml.r = ft_atoi(dest[0]);
	tml.g = ft_atoi(dest[1]);
	tml.b = ft_atoi(dest[2]);
	if ((tml.r < 0 || tml.r > 255) || (tml.g < 0 || tml.g > 255) || \
		(tml.b < 0 || tml.b > 255))
	{
		write(1, "error2\n", 6);//추후 변경
		exit(1);
	}
	return (tml);
}