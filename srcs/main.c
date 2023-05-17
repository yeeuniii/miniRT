#include "../include/main.h"
#include "../include/utils.h"

int	main(int ac, char **av)
{
	t_lights	lights;
	t_object	objects;
	t_mlx		mlx_info;

	init_argv(ac, av, &lights, &objects);
	init_mlx(&mlx_info);
	set_camera(lights.camera, mlx_info.screen);
	draw_objects(lights, objects, mlx_info);
//	test_lights(&lights);
//	test_objects(&objects);
	mlx_loop(mlx_info.mlx);
	return (0);
}
