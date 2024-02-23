/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:01:52 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/23 21:11:05 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*buff_s;
	char	buff_c;

	i = ft_strlen(s);
	buff_s = (char *)s;
	buff_c = (char)c;
	while (i > 0)
	{
		if (buff_s[i] == buff_c)
			return (&buff_s[i]);
		i--;
	}
	if (buff_s[i] == buff_c)
		return ((char *)&buff_s[i]);
	return (NULL);
}
