/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:48:40 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/20 04:10:33 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	draw(&data);
	exit(0);
}

#ifdef DEBUG

__attribute__((destructor)) static void	destructor(void)
{
	system("leaks -q cub3D");
}

#endif
