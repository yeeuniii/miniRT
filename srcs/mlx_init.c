#include "../include/main.h"
#include "../include/utils.h"

static int	key_press(int keycode, t_mlx *m)
{
	if (keycode == KEY_ESC)
	{
		printf("Exit\n");
		mlx_destroy_window(m->mlx, m->win);
		exit(1);
	}
	return (0);
}

static int	destroy_game(t_mlx *m)
{
	printf("Exit\n");
	mlx_destroy_window(m->mlx, m->win);
	exit(1);
	return (0);
}

void	init_mlx(t_mlx *m)
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
	mlx_key_hook(m->win, key_press, m);
	mlx_hook(m->win, ON_DESTROY, 0, destroy_game, m);
}
