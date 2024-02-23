/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 00:10:59 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/23 21:17:44 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static size_t	ft_count_elements(char *str, char c)
{
	size_t	pp_len;

	pp_len = 0;
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		if (*str != c)
			pp_len++;
		while (*str != c && *str != '\0')
			str++;
		while (*str == c && *str != '\0')
			str++;
	}
	return (pp_len);
}

static void	ft_memory_free(char **pp, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(pp[i]);
		i++;
	}
	free(pp);
}

static char	*ft_allocate_memory(char **pp, size_t index, size_t p_len)
{
	char	*p;

	p = ft_calloc(p_len + 1, sizeof(char));
	if (p == NULL)
	{
		ft_memory_free(pp, index);
		return (NULL);
	}
	return (p);
}

static char	**ft_allocate_p(char *str, char c, char **pp)
{
	size_t	i;
	size_t	p_len;
	char	*p;

	i = 0;
	while (*str != '\0')
	{
		if (*str != c)
		{
			p_len = 0;
			while (str[p_len] != c && str[p_len] != '\0')
				p_len++;
			p = ft_allocate_memory(pp, i, p_len);
			if (p == NULL)
				return (NULL);
			ft_strlcpy(p, str, p_len + 1);
			pp[i] = p;
			i++;
		}
		while (*str != c && *str != '\0')
			str++;
		while (*str == c && *str != '\0')
			str++;
	}
	return (pp);
}

char	**ft_split(char const *s, char c)
{
	char	**pp;
	size_t	pp_len;
	char	*str;

	str = (char *)s;
	pp_len = ft_count_elements(str, c);
	pp = ft_calloc(pp_len + 1, sizeof(char *));
	if (pp == NULL)
		return (NULL);
	pp[pp_len] = (char *) NULL;
	if (str == NULL)
		return (pp);
	pp = ft_allocate_p(str, c, pp);
	return (pp);
}
