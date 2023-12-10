/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:04:58 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/11 03:07:04 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	parser(&data, argc, argv);
	printf("==========================================\n");
	printf("north = %s\n", data.texture_path->north);
	printf("south = %s\n", data.texture_path->south);
	printf("west = %s\n", data.texture_path->west);
	printf("east = %s\n", data.texture_path->east);
	printf("==========================================\n");
	printf("floor = %d\n", data.room_color->floor);
	printf("ceiling = %d\n", data.room_color->ceiling);
}

// __attribute__((destructor)) static void destructor() {
// 	system("leaks -q cub3D");
// }
