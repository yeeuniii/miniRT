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