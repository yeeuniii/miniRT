#include "../../include/main.h"
#include "../../include/utils.h"

void	error_exit(char *str, char **s1, char **s2, t_object *o)
{
	if (s1)
		free_split(s1);
	if (s2)
		free_split(s2);
	if (o)
		free_objects(o);
	printf("Error\n");
	printf("%s", str);
	exit(1);
}

void	free_objects(t_object *o)
{
	t_object	*tmp;
	t_object	*n;

	n = o->next;
	free(o->object);
	free(o);
	while (n)
	{
		tmp = n;
		n = n->next;
		free(tmp->object);
		free(tmp);
	}
}

void	free_split(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}
