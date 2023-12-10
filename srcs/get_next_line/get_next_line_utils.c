/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:30:44 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/10 12:42:08 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*buff_s;
	char	buff_c;

	i = 0;
	buff_s = (char *)s;
	buff_c = (char)c;
	while (buff_s[i] != '\0')
	{
		if (buff_s[i] == buff_c)
			return (&buff_s[i]);
		i++;
	}
	if (buff_s[i] == buff_c)
		return (&buff_s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	char	*ptr;
	char	*result;
	size_t	size;
	size_t	i;

	size = 0;
	ptr = (char *)s1;
	size = ft_strlen(ptr);
	dest = malloc(size + 1);
	if (dest == NULL)
		return (NULL);
	result = dest;
	i = 0;
	while (ptr[i] != '\0')
	{
		dest[i] = ptr[i];
		i++;
	}
	dest[i] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (ft_strdup(""));
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr != NULL)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			ptr[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j] != '\0')
		{
			ptr[i + j] = s2[j];
			j++;
		}
		ptr[i + j] = '\0';
	}
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < len)
		str = malloc(ft_strlen(s) + 1);
	else
		str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
