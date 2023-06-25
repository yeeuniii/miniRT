/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoung <junyoung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:52:58 by junyoung          #+#    #+#             */
/*   Updated: 2023/06/25 19:45:50 by junyoung         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

long long	ft_atoi(const char *str);
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t len);

#endif
