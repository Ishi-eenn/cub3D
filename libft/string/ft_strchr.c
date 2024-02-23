/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:21:12 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/23 21:10:36 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

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
