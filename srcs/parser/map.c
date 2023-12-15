/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 03:26:49 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/15 15:20:45 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// void	title(t_data *data, int	fd)
// {
// 	size_t	i;
// 	char	*line;

// 	i = 0;
// 	data->map->map_data = malloc(sizeof(char *) * 1);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break;
// 		data->map->map_data = ft_realloc(data->map->map_data, i);
// 		// ft_realloc(&data->map->map_data, i);
// 		data->map->map_data[i] = line;
// 		printf("%s", data->map->map_data[i]);
// 		i++;
// 	}
// 	data->map->map_data[i] = NULL;
// }

// void	ft_realloc(char **str, size_t size)
// {
// 	size_t	i;
// 	char	**tmp;

// 	i = 0;
// 	tmp = malloc(sizeof(char *) * size);
// 	while (str[i])
// 	{
// 		tmp[i] = ft_strdup(str[i]);
// 		i++;
// 	}
// 	free(str);
// 	str = tmp;
// }

// void	title(t_data *data, int	fd)
// {
// 	size_t	i;
// 	char	*line;
// 	// char	**tmp;

// 	i = 0;
// 	data->map->map_data = malloc(sizeof(char *) * 1);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break;
// 		ft_realloc(data->map->map_data, i);
// 		i++;
// 	}
// 	data->map->map_data[i] = NULL;
// }

// void	title(t_data *data, int fd)
void	title(int fd)
{
	size_t	i;
	char	*line;
	char	**tmp;

	i = 0;
	tmp = malloc(sizeof(char *) * 13);
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		tmp[i] = ft_strdup(line);
		printf("%2zu %s", i, line);
		printf("%2zu %s\n", i, tmp[i]);
		i++;
	}
	printf("i = %zu\n", i);
	tmp[i] = NULL;
	i = 0;
	while (tmp[i])
	{
		printf("%s", tmp[i]);
		i++;
	}
}

void	parse_and_set_map_from_fd(t_data *data, int fd)
{
	data->map = malloc(sizeof(t_map));
	if (data->map == NULL)
		print_error_and_exit("Memory allocation failed.");
	// title(data, fd);
	title(fd);
}
