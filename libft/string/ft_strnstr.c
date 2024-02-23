/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:01:49 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/23 21:11:01 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hi;
	size_t	haystack_len;
	size_t	needle_len;

	if (haystack == NULL && len == 0 && needle != NULL)
		return (NULL);
	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	if (needle_len == 0)
		return ((char *)haystack);
	if (needle_len > haystack_len)
		return (NULL);
	hi = 0;
	while (hi < len && hi < haystack_len && hi + needle_len <= len)
	{
		if (!ft_strncmp(&haystack[hi], needle, needle_len))
			return ((char *)&haystack[hi]);
		hi++;
	}
	return (NULL);
}
