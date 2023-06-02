/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoung <junyoung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:53:03 by junyoung          #+#    #+#             */
/*   Updated: 2023/06/02 13:53:04 by junyoung         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include "../include/utils.h"
#include "../mlx/mlx.h"

int	main(int ac, char **av)
{
	t_lights	lights;
	t_object	*objects;
	t_mlx		mlx_info;

	objects = init_object_start();
	init_argv(ac, av, &lights, objects);
	init_mlx(&mlx_info, &lights, objects);
	set_camera(&lights.camera, mlx_info.screen);
	draw_objects(lights, objects, mlx_info);
	mlx_loop(mlx_info.mlx);
	free_objects(objects);
	return (0);
}
