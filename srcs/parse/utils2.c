#include "../../include/main.h"
#include "../../include/utils.h"

static int	check_sig_double(char *str)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (str[++i])
	{
		if (str[i] == '-' || str[i] == '+')
			flag += 1;
		if (i > 0 && (str[i] == '-' || str[i] == '+') && ft_isdigit(str[i - 1]))
			return (0);
	}
	if (flag > 1)
		return (0);
	else
		return (1);
}

int	check_space_and_digit(char *str)
{
	int	i;

	if (!check_sig_double(str))
		return (0);
	i = -1;
	while (str[++i])
	{
		if (ft_isspace(str[i]))
			continue ;
		if (!ft_isdigit(str[i]) && (str[i] != '-' && str[i] != '+'))
			return (0);
	}
	return (1);
}
