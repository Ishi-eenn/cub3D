/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 03:26:49 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/28 01:11:54 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*get_and_truncate_next_line(int fd, bool is_head)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
	{
		if (is_head)
			print_error_and_exit("malloc failed");
		else
			return (NULL);
	}
	truncate_at_newline(line);
	return (line);
}

static t_list	*read_lines_into_linked_list(int fd)
{
	char	*line;
	t_list	*list;
	t_list	*head;

	head = ft_lstnew(get_and_truncate_next_line(fd, true));
	list = head;
	while (1)
	{
		line = get_and_truncate_next_line(fd, false);
		if (line == NULL)
			break ;
		list->next = ft_lstnew(line);
		list = list->next;
	}
	return (head);
}

static size_t	validate_map_length(t_list *list)
{
	size_t	len;

	len = ft_lstsize(list);
	if (len > MAX_MAP_LINE_LENGTH)
		print_error_and_exit("Map is too long.\n");
	return (len);
}

static char	**list_to_string_array(t_list *list)
{
	char	**map;
	size_t	i;

	i = validate_map_length(list);
	map = malloc(sizeof(char *) * (i + 1));
	if (map == NULL)
		print_error_and_exit("malloc failed");
	i = 0;
	while (list)
	{
		map[i] = ft_strdup((char *)list->content);
		list = list->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	parse_and_set_map_from_fd(t_data *data, int fd)
{
	t_list	*list;

	data->cub->map = malloc(sizeof(t_map));
	if (data->cub->map == NULL)
		print_error_and_exit("Memory allocation failed.");
	list = read_lines_into_linked_list(fd);
	data->cub->map->map_data = list_to_string_array(list);
	ft_lstclear(&list, free);
}
