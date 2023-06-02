/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoung <junyoung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:54:48 by junyoung          #+#    #+#             */
/*   Updated: 2023/06/02 13:54:49 by junyoung         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minirt.h"

t_vector	atof_vector(char *str, t_strs *strs, t_object *o);
t_object	*init_object_start(void);
void		init_argv(int ac, char **av, t_lights *l, t_object *o);
void		init_object(int type, void *object, t_object *o);
void		init_ambient(t_strs *strs, t_lights *l);
void		init_camera(t_strs *strs, t_lights *l);
void		init_light(t_strs *strs, t_lights *l);
void		init_sphere(t_strs *strs, t_object *o);
void		init_plane(t_strs *strs, t_object *o);
void		init_cylinder(t_strs *strs, t_object *o);
void		checking_argv(char *tmp, t_lights *l, t_object *o);

int			check_split_count(char **str);
int			ft_strcmp(char *s1, char *s2);
int			ft_isspace(char c);
int			check_digit(char *str);
int			check_vector_range(t_vector v);
int			check_sig_double2(char *str);
int			check_color_dest(char **dest);
char		**ft_split2(char const *s);
double		ft_atof(char *str);
double		check_all_atof(char *str, t_strs *strs, t_object *o);
t_color		check_color_argv(char *str, t_strs *strs, t_object *o);
t_object	*ft_lstlast(t_object *lst);

//error_functions

void		free_split(char **str);
void		error_exit(char *str, t_strs *strs, t_object *o);
void		free_objects(t_object *o);

void		init_mlx(t_mlx *m, t_lights *lights, t_object *objects);

void		set_camera(t_camera *camera, t_screen screen);
void		adjust_light(t_light *light, t_hitted record);

void		draw_objects(t_lights lights, t_object *objects, t_mlx mlx_info);
t_vector	get_direct(int i, int j, t_screen screen, t_lights lights);
t_color		get_color(t_lights lights, t_object *objects, t_ray ray);

int			hit(t_object *objects, t_ray ray, t_hitted *record);
int			hit_sphere(t_object *object, t_ray ray, t_hitted *record);
int			hit_plane(t_object *object, t_ray ray, t_hitted *record);
int			hit_cylinder(t_object *object, t_ray ray, t_hitted *record);

int			is_valid_root(double root, t_hitted record);
int			is_hitted(t_hitted *record, t_equation *equation);
void		set_normal_vector(t_ray ray, t_hitted *record);
int			is_in_finite_cylinder(t_cylinder cylinder, \
			t_point hitted_point, double	*height);
t_vector	get_cylinder_normal(t_cylinder cylinder, \
			t_hitted *record, double height);

t_color		apply_phong_model(t_lights lights, \
				t_object *objects, t_hitted record);
t_color		apply_ambient(t_lights lights);
int			is_shadow(t_lights lights, t_object *objects, t_hitted record);

#endif
