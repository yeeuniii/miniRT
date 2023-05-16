#include "../../include/main.h"

size_t	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup2(char *src)
{
	int		idx;
	char	*dest;

	if (!src)
		return (NULL);
	idx = ft_strlen2(src);
	dest = (char *)malloc(sizeof(char) * (idx + 1));
	if (!dest)
		return (NULL);
	idx = -1;
	while (src[++idx] != '\0')
		dest[idx] = src[idx];
	dest[idx] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		di;
	int		si;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen2(s1) + ft_strlen2(s2) + 1));
	if (!dest)
		return (NULL);
	di = -1;
	while (s1[++di] != '\0')
		dest[di] = s1[di];
	si = 0;
	while (s2[si] != '\0')
		dest[di++] = s2[si++];
	dest[di] = '\0';
	free (s1);
	return (dest);
}

int	ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == (char)c && i == 0)
			return (1);
		else if (str[i] == (char)c)
			return (i + 1);
	}
	return (0);
}

void	all_free(char *src)
{
	free(src);
	src = NULL;
}
