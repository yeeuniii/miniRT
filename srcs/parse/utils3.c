/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoung <junyoung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:52:28 by junyoung          #+#    #+#             */
/*   Updated: 2023/06/02 13:52:29 by junyoung         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

int	check_split_count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_color_dest(char **dest)
{
	int	i;

	if (check_split_count(dest) != 3)
		return (0);
	i = -1;
	while (dest[++i])
	{
		if (!check_digit(dest[i]))
		{
			return (0);
		}
	}
	return (1);
}
