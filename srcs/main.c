/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:48:40 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/20 01:48:56 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_test(t_data *data)
{
	int	i;

	printf("==========================================\n");
	printf("north = %s\n", data->cub->texture_path->north);
	printf("south = %s\n", data->cub->texture_path->south);
	printf("west = %s\n", data->cub->texture_path->west);
	printf("east = %s\n", data->cub->texture_path->east);
	printf("==========================================\n");
	printf("floor = %d\n", data->cub->room_color->floor);
	printf("ceiling = %d\n", data->cub->room_color->ceiling);
	printf("==========================================\n");
	printf("map_width = %zu\n", data->cub->map->width);
	printf("map_height = %zu\n", data->cub->map->height);
	i = 0;
	while (data->cub->map->map_data[i])
	{
		printf("%s\n", data->cub->map->map_data[i]);
		i++;
	}
}

static void	init_data(t_data *data)
{
	data->cub = malloc(sizeof(t_cub));
	if (!data->cub)
		print_error_and_exit("malloc error");
	data->vector = malloc(sizeof(t_vector));
	if (!data->vector)
		print_error_and_exit("malloc error");
	data->mlx = malloc(sizeof(t_mlx));
	if (!data->mlx)
		print_error_and_exit("malloc error");
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
		print_error_and_exit(ERROR_ARGC);
	init_data(&data);
	parser(argc, argv, &data);
	print_test(&data);
	draw(&data);
	exit(0);
}

#ifdef DEBUG

__attribute__((destructor)) static void	destructor(void)
{
	system("leaks -q cub3D");
}

#endif
