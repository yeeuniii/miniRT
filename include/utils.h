#ifndef UTILS_H
# define UTILS_H

# include "main.h"
//init_functions
t_vec	atof_vector(char *str);
void	init_argv(int ac, char **av, t_lights *l, t_shapes *s);
void	init_ambient(char **str, t_lights *l);
void	init_camera(char **str, t_lights *l);
void	init_light(char **str, t_lights *l);
void	init_sphere(char **str, t_shapes *l);
void	init_plane(char **str, t_shapes *s);
void	init_cylinder(char **str, t_shapes *s);
void	checking_argv(char *tmp, t_lights *l, t_shapes *s);

//utils
int			ft_strcmp(char *s1, char *s2);
int			ft_isspace(char c);
int			check_space_and_digit(char *str);
double		ft_atof(char *str);
double		check_all_atof(char *str);
t_colors	check_color_argv(char *str);
t_shapes	*ft_lstlast(t_shapes *lst);

#endif