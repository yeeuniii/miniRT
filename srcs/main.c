#include "../include/main.h"
#include "../include/utils.h"

int	main(int ac, char **av)
{
	t_lights	lights;
	t_objects	shapes;
	t_mlx		mlx_info;

	init_argv(ac, av, &lights, &shapes);
	init_mlx(&mlx_info);
	set_camera(lights.camera, mlx_info.screen);
//	printf("%f %f %f\n", lights.camera->left_bottom.x, lights.camera->left_bottom.y, lights.camera->left_bottom.z);
//	test_lights(&lights);
//	test_shapes(&shapes);
//mlx_loop(mlx_info.mlx);
	return (0);
}
