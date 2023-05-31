#include "../include/main.h"
#include "../include/utils.h"

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
