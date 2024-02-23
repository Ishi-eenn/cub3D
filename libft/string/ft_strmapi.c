/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 00:11:10 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/23 21:10:56 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*p;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	p = ft_calloc(len + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	p[len] = '\0';
	i = 0;
	while (i < len)
	{
		p[i] = f(i, s[i]);
		i++;
	}
	return (p);
}
