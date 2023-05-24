#ifndef UTILS_H
# define UTILS_H

# include "main.h"

//init_functions

t_vector	atof_vector(char *str, char **s1, t_object *o);
t_object	*init_object_start(void);
void		init_argv(int ac, char **av, t_lights *l, t_object *o);
void		init_object(int type, void *object, t_object *o);
void		init_ambient(char **str, t_lights *l);
void		init_camera(char **str, t_lights *l);
void		init_light(char **str, t_lights *l);
void		init_sphere(char **str, t_object *o);
void		init_plane(char **str, t_object *o);
void		init_cylinder(char **str, t_object *o);
void		checking_argv(char *tmp, t_lights *l, t_object *o);
void		set_camera(t_camera *camera, t_screen screen);

//utils

int			check_split_count(char **str);
int			ft_strcmp(char *s1, char *s2);
int			ft_isspace(char c);
int			check_digit(char *str);
int			check_vector_range(t_vector v);
int			check_sig_double2(char *str);
char		**ft_split2(char const *s);
double		ft_atof(char *str);
double		check_all_atof(char *str, char **s1, char **s2, t_object *o);
t_color		check_color_argv(char *str, char **s, t_object *o);
t_object	*ft_lstlast(t_object *lst);

//error_functions

void		free_split(char **str);
void		error_exit(char *str, char **s1, char **s2, t_object *o);
void		free_objects(t_object *o);

//mlx_functions

void		init_mlx(t_mlx *m);

// object

void		draw_objects(t_lights lights, t_object *objects, t_mlx mlx_info);
t_vector	get_direct(int i, int j, t_screen screen, t_lights lights);
t_color		get_color(t_lights lights, t_object *objects, t_ray ray);

int			hit_sphere(t_sphere sphere, t_ray ray, t_hitted *record);

// phong_model

t_color		apply_phong_model(t_lights lights, t_hitted record);
t_color		apply_ambient(t_lights lights);

//test

void		test_lights(t_lights *l);
void		test_shapes(t_object *s);

#endif
