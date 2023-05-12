/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoung <junyoung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:37:40 by junyoung          #+#    #+#             */
/*   Updated: 2022/12/28 08:25:05 by junyoung         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

size_t	ft_strlen2(const char *str);
char	*ft_strdup2(char *src);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(const char *str, int c);
void	all_free(char *src);

#endif