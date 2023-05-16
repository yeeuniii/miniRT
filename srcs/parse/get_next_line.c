#include "../../include/main.h"

static char	*check_line(char *buf, char *backup, int fd)
{
	int		rl;

	rl = 1;
	while (rl > 0)
	{
		rl = read(fd, buf, 1);
		if (rl == -1)
			return (NULL);
		if (rl == 0)
			break ;
		buf[rl] = '\0';
		if (!backup)
			backup = ft_strdup2("");
		backup = ft_strjoin(backup, buf);
		if (!backup)
			return (NULL);
		if (ft_strchr(backup, '\n') != 0)
			break ;
	}
	return (backup);
}

static char	*get_line(char *backup)
{
	int		idx;
	int		bi;
	char	*temp;

	idx = 0;
	while (backup[idx] != '\n' && backup[idx] != '\0')
		idx++;
	if (backup[idx] == '\n')
		idx++;
	temp = (char *)malloc(sizeof(char) * (idx + 1));
	if (!temp)
		return (NULL);
	bi = -1;
	if (backup[0] == '\n')
		temp[0] = backup[0];
	while (backup[++bi] != '\n' && backup[bi] != '\0')
		temp[bi] = backup[bi];
	if (backup[bi] == '\n')
		temp[bi] = backup[bi];
	temp[idx] = '\0';
	return (temp);
}

static char	*rifining_backup(char *backup)
{
	int		idx;
	char	*new;

	idx = 0;
	while (backup[idx] != '\n' && backup[idx] != '\0')
		idx++;
	if (backup[idx] == '\0' || backup[idx + 1] == '\0')
	{
		all_free(backup);
		return (NULL);
	}
	new = ft_strdup2(&backup[idx + 1]);
	if (!new)
		return (NULL);
	all_free(backup);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*backup;

	if (fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * 2);
	if (!buf)
		return (NULL);
	backup = check_line(buf, backup, fd);
	all_free(buf);
	if (!backup)
		return (NULL);
	line = get_line(backup);
	backup = rifining_backup(backup);
	return (line);
}
