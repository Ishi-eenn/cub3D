#include <math.h>
// #include <stdio.h>

typedef struct s_vector
{
    double x;
    double y;
} t_vector;

void init_vector(t_vector vect_pos, t_vector vect_dir, t_vector vect_plane)
{
    vect_pos.x = 0;
    vect_pos.y = 0;
    vect_dir.x = 1;
    vect_dir.y = 1;
    vect_plane.x = 0;
    vect_plane.y = 0;
}

t_vector   change_angle(t_vector vect_dir,double angle)
{
    vect_dir.x = vect_dir.x * cos(angle) - vect_dir.y * sin(angle);
    vect_dir.y = vect_dir.x * sin(angle) + vect_dir.y * cos(angle);
    return (vect_dir);
}

t_vector   change_position(t_vector vect_pos, t_vector vect_dir, double x,double y)
{
    vect_pos.x = vect_dir.x + x;
    vect_pos.y = vect_dir.y + y;
    return (vect_pos);
}

t_vector   get_vect_ray(t_vector vect_pos, t_vector vect_dir,t_vector vect_plane)
{
    t_vector vect_ray;

    vect_ray.x = vect_pos.x + vect_dir.x * vect_plane.x;
    vect_ray.y = vect_pos.y + vect_dir.y * vect_plane.y;
    return (vect_ray);
}

// int main(void)
// {
//     t_vector vect_pos;
//     t_vector vect_dir;
//     t_vector vect_plane;

//    vect_pos.x = 0;
//    vect_pos.y = 0;
//    vect_dir.x = 1;
//    vect_dir.y = 1;
//    vect_plane.x = 0;
//    vect_plane.y = 0;

// 	void	*img;
// 	void	*mlx;

// 	mlx = mlx_init();
// 	img = mlx_new_image(mlx, 1920, 1080);

//     init_vector(vect_pos, vect_dir, vect_plane);
//     get_vect_ray(vect_pos, vect_dir, vect_plane);
//     return (0);
// }

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
