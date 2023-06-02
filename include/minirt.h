/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoung <junyoung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:54:40 by junyoung          #+#    #+#             */
/*   Updated: 2023/06/02 13:54:40 by junyoung         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//# include <mlx.h>
# include "../libft/libft.h"
# include "struct.h"

# define KEY_ESC 53
# define FRONT 87
# define BACK 84
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ON_DESTROY 17

# define WIDTH 800
# define HEIGHT 600
# define VIEWPORT_HEIGHT 4.0
# define EPSILON 0.000001

typedef struct s_object	t_object;

typedef enum e_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_type;

typedef struct s_lights
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;

}	t_lights;

typedef struct s_object
{
	int			type;
	void		*object;
	t_object	*next;

}	t_object;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_data		data;
	t_screen	screen;
	t_lights	*lights;
	t_object	*object;
}	t_mlx;

#endif
