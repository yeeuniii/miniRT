#include "../../include/main.h"
#include "../../include/utils.h"

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
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, 800, 600, "miniRT");
	mlx_key_hook(m->win, key_press, m);
	mlx_hook(m->win, ON_DESTROY, 0, destroy_game, m);
}