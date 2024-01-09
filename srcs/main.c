/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakaiheizou <nakaiheizou@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:04:58 by tsishika          #+#    #+#             */
/*   Updated: 2024/01/10 02:22:50 by nakaiheizou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

typedef struct	s_mlx_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx_data;

void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	t_data	data;
	void	*mlx;
	void	*mlx_win;
	t_mlx_data	img;

	(void)argc;
	(void)argv;
	// parser(&data, argc, argv);
	// printf("==========================================\n");
	// printf("north = %s\n", data.texture_path->north);
	// printf("south = %s\n", data.texture_path->south);
	// printf("west = %s\n", data.texture_path->west);
	// printf("east = %s\n", data.texture_path->east);
	// printf("==========================================\n");
	// printf("floor = %d\n", data.room_color->floor);
	// printf("ceiling = %d\n", data.room_color->ceiling);

	// size_t	i = 0;
	// while (data.map->map_data[i])
	// {
	// 	printf("%s\n", data.map->map_data[i]);
	// 	i++;
	// }
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello cub3D!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	for (int i = 500; i < 1000; i++)
		for (int j = 300; j < 600; j++)
			my_mlx_pixel_put(&img, i, j, 0x00FFFFFF);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	free(data.texture_path->north);
	free(data.texture_path->south);
	free(data.texture_path->west);
	free(data.texture_path->east);
	free(data.texture_path);
	free(data.room_color);
}

__attribute__((destructor)) static void destructor() {
	system("leaks -q cub3D");
}
