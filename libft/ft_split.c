/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoung <junyoung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 08:14:06 by junyoung          #+#    #+#             */
/*   Updated: 2022/08/11 15:31:02 by junyoung         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_count(char const *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	while (s[i])
	{
		flag = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			flag = 1;
			i++;
		}
		count += flag;
	}
	return (count);
}

static int	ft_free(char **dest, int i)
{
	while (i > 0)
		free(dest[--i]);
	return (0);
}

static char	*ft_strndup(const char *src, int count)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (count + 1));
	if (!dest)
		return (0);
	i = -1;
	while (++i < count)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

static int	solution(const char *s, char c, char **dest, int count)
{
	int	si;
	int	word_count;
	int	i;

	si = 0;
	i = -1;
	while (s[si])
	{
		word_count = 0;
		while (s[si] == c)
			si++;
		while (s[si] && s[si] != c)
		{
			word_count++;
			si++;
		}
		if (++i < count)
		{
			dest[i] = ft_strndup(&s[si - word_count], word_count);
			if (!dest[i])
				return (ft_free(dest, i));
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**dest;
	static int	count;

	if (!s)
		return (NULL);
	count = check_count(s, c);
	dest = (char **)malloc(sizeof(char *) * (count + 1));
	if (!dest)
		return (NULL);
	dest[count] = NULL;
	if (solution(s, c, dest, count) == 0)
	{
		free(dest);
		return (NULL);
	}
	else
		return (dest);
}
