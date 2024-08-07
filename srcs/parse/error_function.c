/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoung <junyoung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:51:19 by junyoung          #+#    #+#             */
/*   Updated: 2023/06/06 12:37:53 by junyoung         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include "../../include/utils.h"
#include <stdio.h>

void	error_exit(char *str, t_strs *strs, t_object *o)
{
	if (strs)
	{
		if (strs->s1)
			free_split(strs->s1);
		if (strs->s2)
			free_split(strs->s2);
	}
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
	str = NULL;
}

int	check_comma(char **str)
{
	int	i;
	int	k;
	int	comma;

	i = -1;
	k = -1;
	comma = 0;
	while (str[++i])
	{
		k = -1;
		while (str[i][++k])
			if (str[i][k] == ',')
				comma++;
	}
	return (comma);
}
