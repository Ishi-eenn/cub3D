/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:48:40 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/28 01:10:28 by tsishika         ###   ########.fr       */
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
	i = 0;
	while (data->cub->map->map_data[i])
	{
		printf("%s\n", data->cub->map->map_data[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_cub	cub;

	if (argc != 2)
		print_error_and_exit(ERROR_ARGC);
	data.cub = &cub;
	parser(argc, argv, &data);
	print_test(&data);
	cub_free(&cub);
}

// __attribute__((destructor)) static void destructor() {
// 	system("leaks -q cub3D");
// }
