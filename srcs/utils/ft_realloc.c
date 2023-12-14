/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:24:27 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/14 10:28:24 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_realloc(char **str, size_t size)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = malloc(sizeof(char) * size);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	free(str);
	str = tmp;
}
