#include "../../include/main.h"
#include "../../include/utils.h"

int	check_split_count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
