/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:30:48 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/28 09:27:51 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

static char	*read_file(int fd, char *buff, char *save)
{
	int		status;
	char	*buff_save;

	status = 1;
	while (status != 0)
	{
		status = read(fd, buff, BUFFER_SIZE);
		if (status == -1)
			return (NULL);
		if (status == 0)
			break ;
		buff[status] = '\0';
		if (save == NULL)
			save = ft_strdup("");
		buff_save = save;
		save = ft_strjoin(buff_save, buff);
		free(buff_save);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (save);
}

static char	*ft_clear(char *line)
{
	size_t	i;
	char	*save;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	save = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*save == '\0')
	{
		free(save);
		save = NULL;
	}
	line[i + 1] = '\0';
	return (save);
}

char	*get_next_line(int fd)
{
	char			*buff;
	char			*line;
	static char		*save[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || OPEN_MAX <= fd)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	line = read_file(fd, buff, save[fd]);
	free(buff);
	if (line != NULL)
		save[fd] = ft_clear(line);
	return (line);
}
