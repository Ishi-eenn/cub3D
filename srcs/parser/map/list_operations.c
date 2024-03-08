/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:20:33 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/08 21:52:30 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	*get_and_truncate_next_line(int fd, bool is_head)
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

t_list	*read_lines_into_linked_list(int fd)
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

char	**list_to_string_array(t_list *list, t_data *data)
{
	char	**map;
	size_t	i;

	map = malloc(sizeof(char *) * (data->cub->map->height + 1));
	if (map == NULL)
		print_error_and_exit("malloc failed");
	i = 0;
	while (list)
	{
		map[i] = ft_strdup((char *)list->content);
		if (map[i] == NULL)
			print_error_and_exit("malloc failed");
		list = list->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}
