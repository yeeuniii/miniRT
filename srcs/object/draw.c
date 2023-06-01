#include "../../include/minirt.h"
#include "../../include/utils.h"

void	put_pixel_mlx(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_rgb(t_color color)
{
	return ((int)color.x << 16 | (int)color.y << 8 | (int)color.z);
}

void	draw_objects(t_lights lights, t_object *objects, t_mlx mlx_info)
{
	int			i;
	int			j;
	t_screen	screen;
	t_color		color;
	t_ray		ray;

	screen = mlx_info.screen;
	i = 0;
	j = screen.height;
	while (j > 0)
	{
		ray = init_ray(lights.camera.origin, get_direct(i, j, screen, lights));
		color = get_color(lights, objects, ray);
		put_pixel_mlx(&mlx_info.data, i, screen.height - j, get_rgb(color));
		i++;
		if (i == screen.width)
		{
			i = 0;
			j--;
		}
	}
	mlx_put_image_to_window(mlx_info.mlx, mlx_info.win,
		mlx_info.data.image, 0, 0);
}
