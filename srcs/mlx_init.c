#include "../include/main.h"
#include "../include/utils.h"

static void	move_camera(t_mlx *m, t_vector vec)
{
	m->lights->camera.origin = \
		vector_plus(m->lights->camera.origin, vec);
	set_camera(&m->lights->camera, m->screen);
	draw_objects(*m->lights, m->object, *m);
}

static int	key_press(int keycode, t_mlx *m)
{
	if (keycode == KEY_ESC)
	{
		printf("Exit\n");
		mlx_destroy_window(m->mlx, m->win);
		exit(1);
	}
	if (keycode == UP)
		move_camera(m, init_vector(0, 0.5, 0));
	if (keycode == DOWN)
		move_camera(m, init_vector(0, -0.5, 0));
	if (keycode == LEFT)
		move_camera(m, init_vector(-0.5, 0, 0));
	if (keycode == RIGHT)
		move_camera(m, init_vector(0.5, 0, 0));
	if (keycode == FRONT)
		move_camera(m, init_vector(0, 0, -0.5));
	if (keycode == BACK)
		move_camera(m, init_vector(0, 0, 0.5));
	return (0);
}

static int	destroy_game(t_mlx *m)
{
	printf("Exit\n");
	mlx_destroy_window(m->mlx, m->win);
	exit(1);
	return (0);
}


void	init_mlx(t_mlx *m, t_lights *lights, t_object *objects)
{
	t_screen	screen;
	t_data		data;

	screen.width = WIDTH;
	screen.height = HEIGHT;
	screen.aspect_ratio = (double)screen.width / (double)screen.height;
	m->screen = screen;
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, screen.width, screen.height, "miniRT");
	data.image = mlx_new_image(m->mlx, screen.width, screen.height);
	data.addr = mlx_get_data_addr(data.image, &data.bits_per_pixel,
			&data.size_line, &data.endian);
	m->data = data;
	m->lights = lights;
	m->object = objects;
	mlx_key_hook(m->win, key_press, m);
	mlx_hook(m->win, ON_DESTROY, 0, destroy_game, m);
}
