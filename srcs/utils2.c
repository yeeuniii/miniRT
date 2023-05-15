#include "../include/main.h"
#include "../include/utils.h"

int	check_space_and_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != 0)
	{
		if (ft_isspace(str[i]))
			continue;
		if ((str[i] == '-' && !ft_isdigit(str[i + 1])) ||
			(str[i] == '+' && !ft_isdigit(str[i + 1])))
			return (0);
		if (str[i + 1] && ft_isdigit(str[i] && !ft_isdigit(str[i + 1])))
			return (0);
	}
	return (1);
}