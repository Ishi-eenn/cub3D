/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 00:10:44 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/23 18:37:13 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

static size_t	ft_intlen(int n)
{
	size_t	len;
	long	buff_n;

	buff_n = n;
	len = 0;
	if (0 >= n)
	{
		buff_n *= -1;
		len++;
	}
	while (buff_n > 0)
	{
		buff_n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	buff_n;
	char	*p;

	len = ft_intlen(n);
	buff_n = n;
	p = ft_calloc(len + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	if (n < 0)
		buff_n *= -1;
	p[len] = '\0';
	while (len > 0)
	{
		p[len - 1] = (buff_n % 10) + '0';
		buff_n /= 10;
		len--;
	}
	if (n < 0)
		p[len] = '-';
	return (p);
}
