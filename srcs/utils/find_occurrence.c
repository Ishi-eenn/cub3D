/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_occurrence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:16:00 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/10 21:21:12 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*find_first_occurrence(const char *s, int c)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			return ((char *)ptr);
		ptr++;
	}
	return (NULL);
}
