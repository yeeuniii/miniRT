#ifndef UTILS_H
# define UTILS_H

# include "main.h"
//init_functions
t_vector	atof_vector(char *str);
void	init_argv(int ac, char **av, t_lights *l, t_objects *s);
void	init_ambient(char **str, t_lights *l);
void	init_camera(char **str, t_lights *l);
void	init_light(char **str, t_lights *l);
void	init_sphere(char **str, t_objects *l);
void	init_plane(char **str, t_objects *s);
void	init_cylinder(char **str, t_objects *s);
void	checking_argv(char *tmp, t_lights *l, t_objects *s);
void	set_camera(t_camera *camera, t_screen screen);

//utils
int			ft_strcmp(char *s1, char *s2);
int			ft_isspace(char c);
int			check_digit(char *str);
int			check_vector_range(t_vector v);
int			check_sig_double2(char *str);
char		**ft_split2(char const *s);
double		ft_atof(char *str);
double		check_all_atof(char *str);
t_color		check_color_argv(char *str);
t_objects	*ft_lstlast(t_objects *lst);

//error_functions

void	error_exit(char *str);

//mlx_functions

void	init_mlx(t_mlx *m);

#endif
