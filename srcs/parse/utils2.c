/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoung <junyoung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:52:25 by junyoung          #+#    #+#             */
/*   Updated: 2023/06/02 13:52:26 by junyoung         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

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

int	check_digit(char *str)
{
	int	i;

	if (!check_sig_double(str))
		return (0);
	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && (str[i] != '-' && str[i] != '+'))
			return (0);
	}
	return (1);
}

int	check_sig_double2(char *str)
{
	int	i;
	int	flag;
	int	flag2;

	flag = 0;
	flag2 = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '-' || str[i] == '+')
			flag += 1;
		if (str[i] == '.')
			flag2 += 1;
	}
	if (flag > 1 || flag2 > 1)
		return (0);
	else
		return (1);
}

int	check_vector_range(t_vector v)
{
	if (get_vector_size(v) != 1)
		return (0);
	return (1);
}

void	init_object(int type, void *object, t_object *o)
{
	t_object	*shape;
	t_object	*tmp;

	tmp = ft_lstlast(o);
	if (!tmp)
	{
		o->type = type;
		o->object = object;
		o->next = NULL;
		return ;
	}
	shape = (t_object *)malloc(sizeof(t_object) * 1);
	shape->type = type;
	shape->object = object;
	shape->next = NULL;
	tmp->next = shape;
}
