/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:01:22 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/23 21:10:17 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*buff_s1;
	unsigned char	*buff_s2;

	buff_s1 = (unsigned char *)s1;
	buff_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (buff_s1[i] == buff_s2[i]))
		i++;
	if (i == n)
		return (0);
	return ((int)(buff_s1[i] - buff_s2[i]));
}
