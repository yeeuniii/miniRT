#include "../../include/main.h"
#include "../../include/utils.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

double ft_atof(char *str)
{
	int		i;
	int		sig;
	double	num;
	double	num2;

	i = -1;
	sig = 1;
	num = 0;
	num2 = 0;
	if (str[0] == '-')
	{
		sig *= -1;
		i++;
	}
	while(str[++i] != '.')
		num = num * 10 + str[i] - '0';
	i = ft_strlen(str);
	while (str[--i] != '.')
	{
		num2 += str[i] - '0';
		num2 *= 0.1;
	}
	return (sig * (num + num2));
}

t_object	*ft_lstlast(t_object *lst)
{
	t_object	*last;

	last = lst;
	if (last->type == -1)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}
